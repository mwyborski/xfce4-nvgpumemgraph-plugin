nvidia GPUMEM Graph plugin for the Xfce4 panel.

This plugin displays a nvidia gpu memory usage graph/bars. Multiple GPU's are supported. The plugin is based on the CPU Graph plugin and uses nvidia-smi to query the GPU memory usage.

A plugin for the GPU load can be found at:
https://github.com/mwyborski/xfce4-nvgpugraph-plugin

![Image of Plugin](https://www.emwesoft.com/images/gpumemgraph.png)


--------
Install on Xubuntu
----
1. clone repository

2. install dependencies:
	
    	sudo apt install xfce4-dev-tools libxfce4ui-2-dev libxfce4panel-2.0-dev
    
3. run:
	
    	./autogen.sh
    	./configure --prefix=/usr
    	make
    	sudo make install
    
4. right-click on the panel and add like any other panel-plugin.




Currently supporting Linux, FreeBSD, NetBSD and OpenBSD, GNU/kFreeBSD and
Solaris. The *BSD support is derived from Riccardo's
<riccardo.persichetti@tin.it> system load plugin.

i18n support is up to 15 fully supported languages, with another 20 partially
supported languages.

--------
How to use
----
Just add it to your xfce pannel, and it should display the GPUMEM usage in an easy
to understand way.

A left click on the plugin will launch xfce4-taskmanager, or if you don't have
it, top in a terminal.

A right click gives access to the usual xfce plugin context menu, from which
properties can be opened. The properties are split into two tabs.

The first tab allows to change the appearance of the main graph. You can select
between 4 modes and 3 color modes, and pick the various colors used. Here is a
description of what the various colors mean in each combination of mode and
color mode.

Color 1: None - Normal: The color of the whole graph.
		LED: The color of the inactive leds.
		No History: The color of the whole "graph".
		
	 Gradient - Normal: The start color of the graph.
		    LED: The color of the inactive leds.
		    No History: The start color of the "graph".
	 
	 Fire - Normal: The start color of the graph.
		LED: The color of the inactive leds.
		No History: The start color of the "graph".

Color 2: None - Normal: This color isn't used.
		LED: The color of the active leds.
		No History: This color isn't used.
	 
	 Gradient - Normal: The end color of the graph.
		    LED: The start color of the leds.
		    No History: The end color of the "graph".

	 Fire - Normal: The end color of the graph.
		LED: The start color of the leds.
		No History: The end color of the "graph".

Color 3: None - Normal: This color isn't used.
		LED: This color isn't used.
		No History: This color isn't used.

	 Gradient - Normal: This color isn't used.
		    LED: The end color of the leds.
		    No History: This color isn't used.

	 Fire - Normal: This color isn't used.
		LED: The end color of the leds.
		No History: This color isn't used.

In the second tab of the properties, the following options are available:

* Update interval: How often the graph is refreshed with new GPUMEM data

* Tracked core: On multi core or multi GPUMEM systems, allows to pick whether GPUMEM
		Graph should display data representing all cores/GPUMEMs or only a
                specific one.

* Width / Height: Depending on the orientation of the xfce panel, allows to
                  change the width or height of the GPUMEM Graph plugin.

* Non-linear time scale: When checked, scrolling will work differently.  Try
                         and see.

* Show frame: If this option is checked it draws a frame around the plugin.

* Show border: If this option is checked, a small blank area is drawn around
               the plugin.

* Show current usage bars: When checked, in addition to the main graph area,
			   the plugin show one bar per core/GPUMEM, displaying the
                           current load of that core/GPUMEM.

* Associated command: Sets the command to run when the plugin is left-clicked.

* Run in a terminal: When checked, the associated command will be run from a
                     terminal, rather than as a graphical application. Useful
                     for example when the associated command is "top".

* Use startup notification: When checked, uses startup notification for the
                            associated command.

Please report any bugs to https://bugs.xfce.org/

Hope this suite your needs.
Regards,
	The authors
