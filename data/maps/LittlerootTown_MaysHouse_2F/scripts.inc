# 1 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_MapScripts::
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnTransition:
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 8, 2
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Ret::
# 29 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnWarp:
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.2byte 0
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PIN
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
# 69 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadedefaultbgm
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 81 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 87 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 1
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 1
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 114 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 1
# 120 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
# 123 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 132 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 1
# 134 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 135 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayEnters:
# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 139 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 142 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 145 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 148 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 149 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 161 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 164 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 165 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 167 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 170 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
# 173 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 176 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 177 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 178 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 180 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
# 189 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 191 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 192 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 193 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 194 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 195 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
# 197 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 198 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 204 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 207 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 210 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 216 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 217 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 218 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 221 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 224 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
# 227 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 231 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 232 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 233 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 234 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 235 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 236 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 239 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 242 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 245 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Rival::
# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
# 248 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
# 250 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
# 251 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 252 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 253 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_May::
# 254 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 256 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Brendan::
# 259 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 262 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_RivalPostLilycove::
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 265 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
# 268 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayPostLilycove::
# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_PC::
# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 310 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 311 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 312 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 313 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 314 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 315 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 316 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 318 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhoAreYou:
# 321 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh?\n"
# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who… Who are you?\p"
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\n"
# 324 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\p"
# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So your move was today.\p"
# 327 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Um… I'm MAY.\n"
# 328 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Glad to meet you!\p"
# 329 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I…\n"
# 330 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 331 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "with POKéMON all over the world.\p"
# 332 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 333 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "my dad, PROF. BIRCH.\p"
# 334 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 336 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eheheh…\p"
# 339 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON!\p"
# 342 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "He's returned to his lab for now.\n"
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "If you don't have a POKéMON,\l"
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "maybe he can give you one!\p"
# 345 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 346 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 347 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayGettingReady:
# 348 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored!\n"
# 349 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items ready, and…$"
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 351 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhoAreYou:
# 352 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey!\n"
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You…\p"
# 354 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who are you?\p"
# 355 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 356 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Moved in next door, right?\p"
# 357 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Dad, PROF. BIRCH, said that our new\n"
# 359 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "next-door neighbor is a GYM LEADER's\l"
# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 361 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "My name's BRENDAN.\n"
# 362 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "a POKéMON?\p"
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON.\p"
# 369 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "He's returned to his lab for now.\n"
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Maybe he can give you a POKéMON!\p"
# 371 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Some other time, okay?$"
# 372 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 373 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanGettingReady:
# 374 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored…\n"
# 375 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items all packed, and…$"
# 376 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_ItsRivalsPokeBall:
# 378 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's {RIVAL}'s POKé BALL!\p"
# 379 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Better leave it right where it is.$"
# 380 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 381 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
# 382 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 383 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking my POKéDEX.\p"
# 384 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's still a lot of POKéMON that\n"
# 385 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I've seen but haven't caught.\p"
# 386 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "And there are many others that\n"
# 387 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I think will evolve.\p"
# 388 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I wonder where I should go catch\n"
# 389 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?$"
# 390 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 391 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhereShouldIGoNext:
# 392 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
# 393 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?\p"
# 394 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wouldn't it be funny if we ran into each\n"
# 395 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "other, {PLAYER}{KUN}?$"
# 396 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 397 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
# 398 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
# 399 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking out my POKéDEX.\p"
# 400 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There are still many POKéMON that\n"
# 401 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I need to catch, I know, but this\l"
# 402 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "is looking pretty good.\p"
# 403 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Checking this POKéDEX out gives me\n"
# 404 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "the urge to hit the road again.$"
# 405 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 406 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
# 407 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
# 408 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "where I should catch POKéMON next.\p"
# 409 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
# 410 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "catching POKéMON, I can pitch you a\l"
# 411 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "battle if you'd like.$"
