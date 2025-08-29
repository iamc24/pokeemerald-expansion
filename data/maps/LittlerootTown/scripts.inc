# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 3 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 4 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 5 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 6 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown/scripts.pory"

# 8 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 9 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 10 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 11 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 12 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 13 "data/maps/LittlerootTown/scripts.pory"

# 14 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 18 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 19 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 22 "data/maps/LittlerootTown/scripts.pory"

# 23 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 24 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 27 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 28 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 29 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 30 "data/maps/LittlerootTown/scripts.pory"

# 31 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 35 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 36 "data/maps/LittlerootTown/scripts.pory"

# 37 "data/maps/LittlerootTown/scripts.pory"

# 38 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 39 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 40 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 41 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 42 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 43 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 44 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 45 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 50 "data/maps/LittlerootTown/scripts.pory"
	end
# 51 "data/maps/LittlerootTown/scripts.pory"

# 52 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 53 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 54 "data/maps/LittlerootTown/scripts.pory"
	return
# 55 "data/maps/LittlerootTown/scripts.pory"

# 56 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 57 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 58 "data/maps/LittlerootTown/scripts.pory"
	return
# 59 "data/maps/LittlerootTown/scripts.pory"

# 60 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 61 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 62 "data/maps/LittlerootTown/scripts.pory"
	return
# 63 "data/maps/LittlerootTown/scripts.pory"

# 64 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 65 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 66 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 67 "data/maps/LittlerootTown/scripts.pory"
	return
# 68 "data/maps/LittlerootTown/scripts.pory"

# 69 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 71 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 72 "data/maps/LittlerootTown/scripts.pory"
	return
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 75 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
# 76 "data/maps/LittlerootTown/scripts.pory"
	return
# 77 "data/maps/LittlerootTown/scripts.pory"

# 78 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 79 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 80 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 1, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 81 "data/maps/LittlerootTown/scripts.pory"
	return
# 82 "data/maps/LittlerootTown/scripts.pory"

# 83 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 84 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
# 85 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 86 "data/maps/LittlerootTown/scripts.pory"
	return
# 87 "data/maps/LittlerootTown/scripts.pory"

# 88 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 89 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 90 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
# 91 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 92 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 93 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 94 "data/maps/LittlerootTown/scripts.pory"
	return
# 95 "data/maps/LittlerootTown/scripts.pory"

# 96 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 97 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
# 98 "data/maps/LittlerootTown/scripts.pory"
	return
# 99 "data/maps/LittlerootTown/scripts.pory"

# 100 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 101 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
# 102 "data/maps/LittlerootTown/scripts.pory"
	return
# 103 "data/maps/LittlerootTown/scripts.pory"

# 104 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 105 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 106 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 107 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 108 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 109 "data/maps/LittlerootTown/scripts.pory"

# 110 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 111 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 112 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 113 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 114 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 115 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 116 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 117 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 118 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 119 "data/maps/LittlerootTown/scripts.pory"
	end
# 120 "data/maps/LittlerootTown/scripts.pory"

# 121 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 122 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 123 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 124 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 125 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 126 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 127 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 128 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 129 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 130 "data/maps/LittlerootTown/scripts.pory"
	end
# 131 "data/maps/LittlerootTown/scripts.pory"

# 132 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 133 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 134 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 135 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 136 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 137 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 138 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 139 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_MOM
# 140 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitHouse
# 141 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 143 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 144 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 145 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 146 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 148 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 149 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachDoor
# 150 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 151 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 152 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 153 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 154 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomEnterHouse
# 155 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 156 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 158 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 159 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_PLAYER, 0
# 160 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 161 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 162 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 163 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 164 "data/maps/LittlerootTown/scripts.pory"
	return
# 165 "data/maps/LittlerootTown/scripts.pory"

# 166 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 167 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 168 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 169 "data/maps/LittlerootTown/scripts.pory"

# 170 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 171 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 172 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 173 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 174 "data/maps/LittlerootTown/scripts.pory"

# 175 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 176 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 177 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 178 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 179 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 180 "data/maps/LittlerootTown/scripts.pory"

# 181 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 182 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 183 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 184 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 185 "data/maps/LittlerootTown/scripts.pory"

# 186 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 187 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 188 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 189 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 190 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 191 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 192 "data/maps/LittlerootTown/scripts.pory"

# 193 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 194 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 195 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 196 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 197 "data/maps/LittlerootTown/scripts.pory"

# 198 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 199 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 200 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 201 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 202 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 203 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 204 "data/maps/LittlerootTown/scripts.pory"

# 205 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 206 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 207 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 208 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
# 209 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 210 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 211 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 212 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 213 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 214 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 215 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 216 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 217 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 218 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 219 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 220 "data/maps/LittlerootTown/scripts.pory"
	end
# 221 "data/maps/LittlerootTown/scripts.pory"

# 222 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 223 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 224 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 225 "data/maps/LittlerootTown/scripts.pory"

# 226 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 227 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_BIRCH
# 228 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_RIVAL
# 229 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 230 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 231 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 232 "data/maps/LittlerootTown/scripts.pory"
	end
# 233 "data/maps/LittlerootTown/scripts.pory"

# 234 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 235 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
# 236 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
# 237 "data/maps/LittlerootTown/scripts.pory"
	end
# 238 "data/maps/LittlerootTown/scripts.pory"

# 239 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 240 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
# 241 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
# 242 "data/maps/LittlerootTown/scripts.pory"
	end
# 243 "data/maps/LittlerootTown/scripts.pory"

# 244 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 245 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 246 "data/maps/LittlerootTown/scripts.pory"
	end
# 247 "data/maps/LittlerootTown/scripts.pory"

# 248 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 249 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 250 "data/maps/LittlerootTown/scripts.pory"
	end
# 251 "data/maps/LittlerootTown/scripts.pory"

# 252 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 253 "data/maps/LittlerootTown/scripts.pory"
	lock
# 254 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 255 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 256 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 257 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 258 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 259 "data/maps/LittlerootTown/scripts.pory"
	release
# 260 "data/maps/LittlerootTown/scripts.pory"
	end
# 261 "data/maps/LittlerootTown/scripts.pory"

# 262 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 263 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 264 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 265 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 266 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 267 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 268 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 269 "data/maps/LittlerootTown/scripts.pory"
	release
# 270 "data/maps/LittlerootTown/scripts.pory"
	end
# 271 "data/maps/LittlerootTown/scripts.pory"

# 272 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 273 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 274 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 275 "data/maps/LittlerootTown/scripts.pory"
	release
# 276 "data/maps/LittlerootTown/scripts.pory"
	end
# 277 "data/maps/LittlerootTown/scripts.pory"

# 278 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 279 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 280 "data/maps/LittlerootTown/scripts.pory"
	release
# 281 "data/maps/LittlerootTown/scripts.pory"
	end
# 282 "data/maps/LittlerootTown/scripts.pory"

# 283 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 284 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 285 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 286 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 287 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 288 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 289 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 290 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 291 "data/maps/LittlerootTown/scripts.pory"
	end
# 292 "data/maps/LittlerootTown/scripts.pory"

# 293 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 294 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 295 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 296 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 297 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 298 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 300 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 301 "data/maps/LittlerootTown/scripts.pory"
	return
# 302 "data/maps/LittlerootTown/scripts.pory"

# 303 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 304 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 305 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 306 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 307 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 308 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 309 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 310 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 311 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 312 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 313 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 316 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 317 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 318 "data/maps/LittlerootTown/scripts.pory"

# 319 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 320 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 322 "data/maps/LittlerootTown/scripts.pory"

# 323 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 324 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 325 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 326 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 327 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 328 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 329 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 333 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 334 "data/maps/LittlerootTown/scripts.pory"

# 335 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 336 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 337 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 338 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 339 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 340 "data/maps/LittlerootTown/scripts.pory"

# 341 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 342 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 343 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 344 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 345 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 346 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
# 347 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 348 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 349 "data/maps/LittlerootTown/scripts.pory"
	end
# 350 "data/maps/LittlerootTown/scripts.pory"

# 351 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 352 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 353 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 354 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 355 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 356 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 357 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 358 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 359 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 360 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 361 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 362 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 363 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 364 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 365 "data/maps/LittlerootTown/scripts.pory"

# 366 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 367 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 368 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 369 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 370 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 371 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 372 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 373 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 374 "data/maps/LittlerootTown/scripts.pory"

# 375 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GetStarterTriggerLeft::
# 376 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 377 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 378 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 379 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemonGetStarter
# 380 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 381 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 383 "data/maps/LittlerootTown/scripts.pory"
	end
# 384 "data/maps/LittlerootTown/scripts.pory"

# 385 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GetStarterTriggerRight::
# 386 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 387 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 388 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 389 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemonGetStarter
# 390 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
# 391 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 392 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 393 "data/maps/LittlerootTown/scripts.pory"
	end
# 394 "data/maps/LittlerootTown/scripts.pory"

# 395 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemonGetStarter::
# 396 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 397 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 398 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 399 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 400 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 401 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 402 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoGetStarter, MSGBOX_DEFAULT
# 403 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 404 "data/maps/LittlerootTown/scripts.pory"
	return
# 405 "data/maps/LittlerootTown/scripts.pory"

# 406 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 407 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 408 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
# 409 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 410 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 411 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 412 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 413 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 414 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 415 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 416 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 417 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 418 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 419 "data/maps/LittlerootTown/scripts.pory"
	end
# 420 "data/maps/LittlerootTown/scripts.pory"

# 421 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 422 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 423 "data/maps/LittlerootTown/scripts.pory"
	end
# 424 "data/maps/LittlerootTown/scripts.pory"

# 425 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 426 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 427 "data/maps/LittlerootTown/scripts.pory"
	end
# 428 "data/maps/LittlerootTown/scripts.pory"

# 429 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 430 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 431 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 432 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 433 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 434 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 435 "data/maps/LittlerootTown/scripts.pory"
	end
# 436 "data/maps/LittlerootTown/scripts.pory"

# 437 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 438 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 439 "data/maps/LittlerootTown/scripts.pory"
	return
# 440 "data/maps/LittlerootTown/scripts.pory"

# 441 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 442 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 443 "data/maps/LittlerootTown/scripts.pory"
	return
# 444 "data/maps/LittlerootTown/scripts.pory"

# 445 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 446 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 447 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 448 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 449 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 450 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 451 "data/maps/LittlerootTown/scripts.pory"
	end
# 452 "data/maps/LittlerootTown/scripts.pory"

# 453 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 454 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 455 "data/maps/LittlerootTown/scripts.pory"
	return
# 456 "data/maps/LittlerootTown/scripts.pory"

# 457 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 458 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 459 "data/maps/LittlerootTown/scripts.pory"
	return
# 460 "data/maps/LittlerootTown/scripts.pory"

# 461 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 462 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 463 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 464 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_MOM, 10, 9
# 465 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 466 "data/maps/LittlerootTown/scripts.pory"
	end
# 467 "data/maps/LittlerootTown/scripts.pory"

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 469 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 470 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 471 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 9
# 472 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 473 "data/maps/LittlerootTown/scripts.pory"
	end
# 474 "data/maps/LittlerootTown/scripts.pory"

# 475 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 476 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 477 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 478 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 479 "data/maps/LittlerootTown/scripts.pory"
	end
# 480 "data/maps/LittlerootTown/scripts.pory"

# 481 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 482 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 483 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 484 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 485 "data/maps/LittlerootTown/scripts.pory"
	end
# 486 "data/maps/LittlerootTown/scripts.pory"

# 487 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 488 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 489 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 490 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 491 "data/maps/LittlerootTown/scripts.pory"
	end
# 492 "data/maps/LittlerootTown/scripts.pory"

# 493 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 494 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 495 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 496 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 497 "data/maps/LittlerootTown/scripts.pory"
	end
# 498 "data/maps/LittlerootTown/scripts.pory"

# 499 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 500 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 501 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 502 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 503 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 504 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 505 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 506 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 507 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 508 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 509 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 510 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 511 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 512 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 513 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 514 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 515 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 516 "data/maps/LittlerootTown/scripts.pory"
	end
# 517 "data/maps/LittlerootTown/scripts.pory"

# 518 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 519 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 520 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 521 "data/maps/LittlerootTown/scripts.pory"
	return
# 522 "data/maps/LittlerootTown/scripts.pory"

# 523 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 524 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 525 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 526 "data/maps/LittlerootTown/scripts.pory"
	return
# 527 "data/maps/LittlerootTown/scripts.pory"

# 528 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 529 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
# 530 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 531 "data/maps/LittlerootTown/scripts.pory"
	return
# 532 "data/maps/LittlerootTown/scripts.pory"

# 533 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 534 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
# 535 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown/scripts.pory"
	return
# 537 "data/maps/LittlerootTown/scripts.pory"

# 538 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 539 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 540 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 541 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 542 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 543 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 544 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 545 "data/maps/LittlerootTown/scripts.pory"
	return
# 546 "data/maps/LittlerootTown/scripts.pory"

# 547 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 548 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 549 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 550 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 551 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 552 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 553 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 554 "data/maps/LittlerootTown/scripts.pory"
	return
# 555 "data/maps/LittlerootTown/scripts.pory"

# 556 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 557 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 558 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 559 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 560 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 561 "data/maps/LittlerootTown/scripts.pory"
	return
# 562 "data/maps/LittlerootTown/scripts.pory"

# 563 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 564 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 565 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 566 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 567 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 568 "data/maps/LittlerootTown/scripts.pory"
	return
# 569 "data/maps/LittlerootTown/scripts.pory"

# 570 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 571 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 572 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 573 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 574 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 575 "data/maps/LittlerootTown/scripts.pory"
	return
# 576 "data/maps/LittlerootTown/scripts.pory"

# 577 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 578 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 579 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 580 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 581 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 582 "data/maps/LittlerootTown/scripts.pory"
	return
# 583 "data/maps/LittlerootTown/scripts.pory"

# 584 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 585 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 586 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 588 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 589 "data/maps/LittlerootTown/scripts.pory"
	return
# 590 "data/maps/LittlerootTown/scripts.pory"

# 591 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 592 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 593 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 594 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 595 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 596 "data/maps/LittlerootTown/scripts.pory"
	return
# 597 "data/maps/LittlerootTown/scripts.pory"

# 598 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 599 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 600 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 601 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 602 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 603 "data/maps/LittlerootTown/scripts.pory"
	return
# 604 "data/maps/LittlerootTown/scripts.pory"

# 605 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 606 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 608 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 609 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 610 "data/maps/LittlerootTown/scripts.pory"
	return
# 611 "data/maps/LittlerootTown/scripts.pory"

# 612 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 613 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 614 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 616 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 617 "data/maps/LittlerootTown/scripts.pory"
	return
# 618 "data/maps/LittlerootTown/scripts.pory"

# 619 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 623 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 624 "data/maps/LittlerootTown/scripts.pory"
	return
# 625 "data/maps/LittlerootTown/scripts.pory"

# 626 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 627 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 628 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 629 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 630 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 631 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 632 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 633 "data/maps/LittlerootTown/scripts.pory"
	return
# 634 "data/maps/LittlerootTown/scripts.pory"

# 635 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 636 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 637 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 638 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 639 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 640 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 641 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 642 "data/maps/LittlerootTown/scripts.pory"
	return
# 643 "data/maps/LittlerootTown/scripts.pory"

# 644 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 645 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
# 646 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 647 "data/maps/LittlerootTown/scripts.pory"
	return
# 648 "data/maps/LittlerootTown/scripts.pory"

# 649 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/LittlerootTown/scripts.pory"
	return
# 653 "data/maps/LittlerootTown/scripts.pory"

# 654 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 655 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 656 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 657 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 658 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 659 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 660 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 661 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 662 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 663 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 664 "data/maps/LittlerootTown/scripts.pory"
	return
# 665 "data/maps/LittlerootTown/scripts.pory"

# 666 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 667 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 668 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 669 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 670 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 671 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 672 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 673 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 674 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 676 "data/maps/LittlerootTown/scripts.pory"
	return
# 677 "data/maps/LittlerootTown/scripts.pory"

# 678 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 679 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 680 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 681 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 684 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 685 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 686 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 687 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 688 "data/maps/LittlerootTown/scripts.pory"
	return
# 689 "data/maps/LittlerootTown/scripts.pory"

# 690 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 692 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 693 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 694 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 695 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 696 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 697 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 698 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 699 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 700 "data/maps/LittlerootTown/scripts.pory"
	return
# 701 "data/maps/LittlerootTown/scripts.pory"

# 702 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 703 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 704 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 705 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 706 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 707 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 710 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 711 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 712 "data/maps/LittlerootTown/scripts.pory"
	return
# 713 "data/maps/LittlerootTown/scripts.pory"

# 714 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 715 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 716 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 717 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 719 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 720 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 721 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 722 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 723 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 724 "data/maps/LittlerootTown/scripts.pory"
	return
# 725 "data/maps/LittlerootTown/scripts.pory"

# 726 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 727 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 728 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 729 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 730 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 733 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 734 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 735 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 736 "data/maps/LittlerootTown/scripts.pory"
	return
# 737 "data/maps/LittlerootTown/scripts.pory"

# 738 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 739 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 740 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 741 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 742 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 743 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 744 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 745 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 746 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 748 "data/maps/LittlerootTown/scripts.pory"
	return
# 749 "data/maps/LittlerootTown/scripts.pory"

# 750 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 756 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 757 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 758 "data/maps/LittlerootTown/scripts.pory"

# 759 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 762 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 763 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 764 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 765 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 766 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 767 "data/maps/LittlerootTown/scripts.pory"

# 768 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 769 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 770 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 771 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 773 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 774 "data/maps/LittlerootTown/scripts.pory"

# 775 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 778 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 779 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 781 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 782 "data/maps/LittlerootTown/scripts.pory"

# 783 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 785 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 786 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 787 "data/maps/LittlerootTown/scripts.pory"

# 788 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 790 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 791 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 792 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 793 "data/maps/LittlerootTown/scripts.pory"

# 794 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 797 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 798 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 799 "data/maps/LittlerootTown/scripts.pory"

# 800 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 801 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 802 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 803 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 804 "data/maps/LittlerootTown/scripts.pory"

# 805 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 807 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 809 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 810 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 811 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 812 "data/maps/LittlerootTown/scripts.pory"

# 813 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 814 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 815 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 817 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 818 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 819 "data/maps/LittlerootTown/scripts.pory"

# 820 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 822 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 823 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 824 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 826 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 827 "data/maps/LittlerootTown/scripts.pory"

# 828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 832 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 834 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 835 "data/maps/LittlerootTown/scripts.pory"

# 836 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 839 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 842 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 843 "data/maps/LittlerootTown/scripts.pory"

# 844 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 846 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 847 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 851 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 852 "data/maps/LittlerootTown/scripts.pory"

# 853 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 854 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 857 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 858 "data/maps/LittlerootTown/scripts.pory"

# 859 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 862 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 863 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 864 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 865 "data/maps/LittlerootTown/scripts.pory"

# 866 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 867 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 870 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 871 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 872 "data/maps/LittlerootTown/scripts.pory"

# 873 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 874 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 875 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 877 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 878 "data/maps/LittlerootTown/scripts.pory"

# 879 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 883 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 885 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 886 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 887 "data/maps/LittlerootTown/scripts.pory"

# 888 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 889 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 890 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 891 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 894 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 895 "data/maps/LittlerootTown/scripts.pory"

# 896 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 897 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 898 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 899 "data/maps/LittlerootTown/scripts.pory"

# 900 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 901 "data/maps/LittlerootTown/scripts.pory"
	lock
# 902 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 903 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 904 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 905 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 906 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 907 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
# 908 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 909 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 910 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 911 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 912 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 913 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 914 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 915 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 916 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 917 "data/maps/LittlerootTown/scripts.pory"
	end
# 918 "data/maps/LittlerootTown/scripts.pory"

# 919 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 920 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_LITTLEROOT_MOM
# 921 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 922 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 923 "data/maps/LittlerootTown/scripts.pory"
	release
# 924 "data/maps/LittlerootTown/scripts.pory"
	end
# 925 "data/maps/LittlerootTown/scripts.pory"

# 926 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 927 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 928 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 929 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 930 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 931 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 932 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 933 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 934 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 935 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 936 "data/maps/LittlerootTown/scripts.pory"
	return
# 937 "data/maps/LittlerootTown/scripts.pory"

# 938 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 939 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 941 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 942 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 943 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 946 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 947 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 949 "data/maps/LittlerootTown/scripts.pory"

# 950 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 951 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 952 "data/maps/LittlerootTown/scripts.pory"

# 953 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 955 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 956 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 959 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 960 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 961 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 962 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 963 "data/maps/LittlerootTown/scripts.pory"

# 964 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 965 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 966 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 967 "data/maps/LittlerootTown/scripts.pory"

# 968 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 969 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 973 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 975 "data/maps/LittlerootTown/scripts.pory"

# 976 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 977 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 978 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 981 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 982 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 985 "data/maps/LittlerootTown/scripts.pory"

# 986 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 989 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 990 "data/maps/LittlerootTown/scripts.pory"

# 991 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 994 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 995 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 997 "data/maps/LittlerootTown/scripts.pory"

# 998 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 1002 "data/maps/LittlerootTown/scripts.pory"

# 1003 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 1004 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 1005 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 1006 "data/maps/LittlerootTown/scripts.pory"

# 1007 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoGetStarter:
# 1008 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH just returned from the wild.\p"
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "You can go get your first POKéMON from him!$"
# 1010 "data/maps/LittlerootTown/scripts.pory"

# 1011 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 1012 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 1016 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 1019 "data/maps/LittlerootTown/scripts.pory"

# 1020 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 1022 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 1023 "data/maps/LittlerootTown/scripts.pory"

# 1024 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 1026 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 1027 "data/maps/LittlerootTown/scripts.pory"

# 1028 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 1029 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 1030 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1031 "data/maps/LittlerootTown/scripts.pory"

# 1032 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1033 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1034 "data/maps/LittlerootTown/scripts.pory"

# 1035 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1037 "data/maps/LittlerootTown/scripts.pory"

# 1038 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1039 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1040 "data/maps/LittlerootTown/scripts.pory"

# 1041 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1042 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1043 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1046 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1047 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1048 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1049 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1050 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"
