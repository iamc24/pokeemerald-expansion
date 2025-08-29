DebugRoom_MapScripts::
# 2 "data/maps/DebugRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DebugRoom_OnTransition
	.byte 0


DebugRoom_OnTransition::
# 6 "data/maps/DebugRoom/scripts.pory"
	setrespawn HEAL_LOCATION_DEBUG_ROOM
	end


DebugRoom_StevenTest::
# 11 "data/maps/DebugRoom/scripts.pory"
	setflag FLAG_DYNAMAX_BATTLE
# 12 "data/maps/DebugRoom/scripts.pory"
	call MeteorFalls_StevensCave_EventScript_Steven
	return

