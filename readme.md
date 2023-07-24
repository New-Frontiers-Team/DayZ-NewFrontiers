# New Frontiers Mod
A set of mods focused on team dynamics and sense of progression.

## Setup
First of all install and run DayZ from Steam, them install DayZ Tools from Steam too.

After the installation open the DayZ Tools and on settings configure the Project Drive path, then mount the P:\ drive.

Next you will need to set an Environment Variable on your system pointing to the DayZ Tools installation folder named "DAYZ_TOOLS" and another named "DAYZ_FOLDER" pointing to the game installation folder, it will be needed to some scripts work.

Install the Community Framework mod from the DayZ Workshop on Steam.

Run the setup.bat that is inside the scripts folder, it will create the symbolic links and run the first build.

## Running
Download the latest DayZ Server from Steam and copy mpmissions folder and serverDZ.cfg file to your DayZ gane folder.

Change those options on your new serverDZ.cfg:
```
BattlEye = 0;			// turn off BE since diag exe does not run with it
verifySignatures = 0;	// if testing mods which aren't properly signed yet
allowFilePatching = 1;  // allow clients with unpacked data to join
```

Run the server.bat script to start the server on test mode and client.bat to start the game and connect to the server.

## Debugging and File Patching
To develop and debug run the workbench.bat script, it will open the Enfusion Workbench with the mods loaded and file patching enabled, so you can edit the mod and recompile it using ctrl + F7 during runtime.