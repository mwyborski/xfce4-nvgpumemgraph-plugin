/*  os.c
 *  Part of xfce4-cpugraph-plugin
 *
 *  Copyright (c) Alexander Nordfelth <alex.nordfelth@telia.com>
 *  Copyright (c) gatopeich <gatoguan-os@yahoo.com>
 *  Copyright (c) 2007-2008 Angelo Arrifano <miknix@gmail.com>
 *  Copyright (c) 2007-2008 Lidiriel <lidiriel@coriolys.org>
 *  Copyright (c) 2010 Florian Rivoal <frivoal@gmail.com>
 *  Copyright (c) 2010 Peter Tribble <peter.tribble@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "os.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NV_SMI "nvidia-smi --query-gpu=memory.total,memory.used --format=csv"
#define NV_SMI_QUERY_HEADER "memory.total [MiB], memory.used [MiB]"
#define NV_SMI_QUERY_HEADER_LEN 37
#define QUERYMAXLEN 256


guint
detect_cpu_number ()
{
    FILE *fp;
    gchar query_string[QUERYMAXLEN];
    guint gpumem_count = 0;

    fp = popen(NV_SMI, "r");
    if (fp == NULL)
        return 0;


    if ((fgets(query_string, sizeof(query_string), fp) != NULL) &&	
	    (strncmp (query_string, NV_SMI_QUERY_HEADER, NV_SMI_QUERY_HEADER_LEN) == 0))
    {

        while (fgets(query_string, sizeof(query_string), fp) != NULL) 
            gpumem_count++;
    }

    pclose(fp);

    return gpumem_count;
}

gboolean
read_cpu_data (CpuData *data, guint nb_cpu)
{
    FILE *fp;
    gchar query_string[QUERYMAXLEN];
    guint line = 0;
    guint mem_total;
    guint mem_used;

    fp = popen(NV_SMI, "r");
    if (fp == NULL)
    return FALSE;

    data[0].load = 0;

    if ((fgets(query_string, sizeof(query_string), fp) != NULL) &&	
	    (strncmp (query_string, NV_SMI_QUERY_HEADER, NV_SMI_QUERY_HEADER_LEN) == 0))
    {

        while ((fgets(query_string, sizeof(query_string), fp) != NULL) &&
                (line < nb_cpu))
        {
            
            if (sscanf (query_string, "%u MiB, %u MiB", &mem_total, &mem_used) < 1)
            {
                pclose(fp);
                return FALSE;
            }

            guint utilization = roundf((float) mem_used * 100.0f / (float) mem_total);
            data[nb_cpu - line].load = utilization;
            data[nb_cpu - line].previous_used = mem_used;
            data[nb_cpu - line].previous_total = mem_total;
            data[0].load += utilization;
            line++;
        }

    }

    data[0].load = roundf((float) data[0].load / (float)nb_cpu);

    pclose(fp);

    return TRUE;
}

