# 1 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 2 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_MapScripts::
# 3 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 4 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 5 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 6 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 8 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 9 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 10 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 11 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 12 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Hoenn mons
# 13 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 14 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 15 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 16 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 17 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Birch ready to meet
# 18 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Birch met and ready to choose starter
# 19 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 20 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 103
# 21 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 22 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 23 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnTransition:
# 24 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 25 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 26 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 27 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 28 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 29 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 31 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 32 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 33 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 34 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 35 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 36 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 37 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 38 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 39 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 40 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 41 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 42 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 43 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 44 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 45 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 46 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 47 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 48 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 49 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 50 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 51 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 52 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnWarp:
# 53 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 54 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 55 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 56 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 57 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 58 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 59 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 60 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 61 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 62 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 63 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 64 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 65 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 66 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 67 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 68 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_BIRCH
# 69 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 70 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
# 71 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 9, 6
# 72 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 73 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 8, 5
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 79 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 81 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 83 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 84 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 85 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 86 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 87 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
# 88 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
# 89 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
# 90 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
# 91 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
# 92 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
# 93 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 94 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
# 95 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
# 96 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
# 97 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 98 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 99 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnFrame:
# 100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_0x8004, 0
# 110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_up
# 151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PC_ON
# 176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitse
# 177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 186 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 187 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 189 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 192 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 193 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 194 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 195 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 202 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 203 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 204 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 212 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 213 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 214 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 224 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 225 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 226 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_up
# 228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 231 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 232 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 233 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 244 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 245 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 246 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 250 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 256 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 257 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 258 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
# 262 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 263 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 264 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 265 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 269 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 270 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 272 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 273 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 274 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 275 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 289 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 290 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 291 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 292 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
# 293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
# 304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 306 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 309 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 310 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 311 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 312 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 313 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 322 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5
# 329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 330 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 331 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 332 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 333 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 338 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 340 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 342 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 350 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 351 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 352 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 353 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 354 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 356 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 358 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 359 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 364 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 365 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 366 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 367 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5
# 370 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 371 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 372 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 373 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 376 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 377 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 379 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 380 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 391 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 392 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 398 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 399 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 400 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 401 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 404 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 405 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 406 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 407 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 408 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5
# 411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 415 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 416 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 418 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 420 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 421 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 422 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 423 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 427 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 431 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 432 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 435 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 436 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 437 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 438 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 444 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 445 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 446 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 447 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 448 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 449 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 450 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
# 456 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 463 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 474 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 480 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_BirchRivalGoneHome
# 481 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WaitStarterPick, MSGBOX_DEFAULT
# 482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 483 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 485 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BirchRivalGoneHome::
# 486 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 487 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 488 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch::
# 491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 498 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 499 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 500 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 501 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 504 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 505 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 506 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 507 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 517 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 518 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 519 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 520 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 523 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 524 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 525 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 526 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 527 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 534 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 535 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 537 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 539 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 540 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 541 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 542 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 543 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 550 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 551 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 553 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 555 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 556 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 557 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 558 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 559 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 566 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 567 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_left
# 569 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 571 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
# 572 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 573 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 574 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 575 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
# 576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 582 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 583 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 585 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 587 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 588 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 589 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 590 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 591 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 598 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 599 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 601 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 602 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 604 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 606 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 607 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 608 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 609 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 610 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 611 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 612 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 613 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 614 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 615 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 616 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 617 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 618 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 619 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 620 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 621 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 622 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 623 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 624 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 625 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 626 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 627 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 628 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 629 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 630 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 631 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 632 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 633 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 634 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 635 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 636 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 637 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 638 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 639 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 640 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PC::
# 641 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 642 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 643 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 644 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 645 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 646 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 647 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 648 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Book::
# 649 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 650 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 651 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 652 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 653 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 654 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 655 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 656 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 657 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 658 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 659 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 660 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 661 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 662 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 663 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 664 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 665 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 666 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 667 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 668 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 669 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 670 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 671 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 672 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 673 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 674 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 675 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 676 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 677 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 678 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 679 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 680 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 681 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 682 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 683 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 684 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 685 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 686 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 687 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 688 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
# 689 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 690 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 691 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 692 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: If you work at POKéMON\n"
# 693 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you'll make\l"
# 694 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "an extremely good TRAINER.\p"
# 695 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, is also studying\n"
# 696 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON while helping me out.\p"
# 697 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
# 698 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a good idea to go see {RIVAL}?$"
# 699 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 700 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 701 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Great!\n"
# 702 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} should be happy, too.\p"
# 703 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Get {RIVAL} to teach you what it\n"
# 704 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "means to be a TRAINER.$"
# 705 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 706 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 707 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, don't be that way.\n"
# 708 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You should go meet my kid.$"
# 709 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 710 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 711 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {RIVAL}?\n"
# 712 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Gone home, I think.\p"
# 713 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or maybe that kid's scrabbling around\n"
# 714 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in tall grass again somewhere…\p"
# 715 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you or your POKéMON get tired,\n"
# 716 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you should get some rest at home.$"
# 717 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 718 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 719 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 720 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL} on\n"
# 721 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "your first try. That's excellent!\p"
# 722 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}'s been helping with my research\n"
# 723 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a long time.\p"
# 724 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} has an extensive history as\n"
# 725 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a TRAINER already.\p"
# 726 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 727 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 728 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéDEX.$"
# 729 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 730 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 731 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"
# 732 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 733 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 734 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 735 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "tool that automatically makes a record\l"
# 736 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of any POKéMON you meet or catch.\p"
# 737 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, goes everywhere\n"
# 738 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "with it.\p"
# 739 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Whenever my kid catches a rare POKéMON\n"
# 740 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and records its data in the POKéDEX,\l"
# 741 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "why, {RIVAL} looks for me while I'm out\l"
# 742 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "doing fieldwork, and shows me.$"
# 743 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 744 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 745 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Countless POKéMON\n"
# 746 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 747 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 748 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 749 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 750 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 751 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 752 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a POKéDEX, too!\p"
# 753 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's great! Just like me!\n"
# 754 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've got something for you, too!$"
# 755 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 756 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 757 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: It's fun if you can get a lot of\n"
# 758 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON!\p"
# 759 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to look all over the place\n"
# 760 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "because I want different POKéMON.\p"
# 761 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cute POKéMON, I'll catch\n"
# 762 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "them with POKé BALLS!$"
# 763 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 764 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 765 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your BAG's full.$"
# 766 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 767 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 768 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I wonder where I should go look\n"
# 769 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for POKéMON next?$"
# 770 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 771 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 772 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Huh…\n"
# 773 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a POKéDEX, too.\p"
# 774 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well then, here.\n"
# 775 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll give you these.$"
# 776 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 777 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 778 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: You know it's more fun to\n"
# 779 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "have a whole bunch of POKéMON.\p"
# 780 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to explore all over the place\n"
# 781 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to find different POKéMON.\p"
# 782 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cool POKéMON, you bet\n"
# 783 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll try to get them with POKé BALLS.$"
# 784 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 785 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 786 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your BAG's full.$"
# 787 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 788 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 789 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Where should I look for\n"
# 790 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON next…$"
# 791 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 792 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 793 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 794 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF must use this for research.$"
# 795 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 796 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 797 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 798 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 799 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 800 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 801 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on POKéMON.$"
# 802 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 803 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 804 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 805 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 806 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 807 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Now…\p"
# 808 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 809 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study POKéMON.\p"
# 810 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 811 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 812 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the HOENN region,\n"
# 813 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also POKéMON from other\l"
# 814 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "regions.\p"
# 815 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It goes to show how rich and varied\n"
# 816 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the natural environments of HOENN\l"
# 817 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "happen to be.\p"
# 818 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's why I think it's necessary for\n"
# 819 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "me to upgrade your POKéDEX to\l"
# 820 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode.\p"
# 821 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, let me see your POKéDEX units.$"
# 822 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 823 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 824 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Eheheh!\p"
# 825 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cool that even my POKéDEX\n"
# 826 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "is getting updated!\p"
# 827 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's because you went out and caught\n"
# 828 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
# 829 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 830 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 831 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: I went out all over HOENN\n"
# 832 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and checked out POKéMON.\p"
# 833 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can thank me for getting\n"
# 834 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode POKéDEX.\p"
# 835 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yep, you're lucky, {PLAYER}!$"
# 836 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 837 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
# 838 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Okay, all done!$"
# 839 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 840 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 841 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 842 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to the NATIONAL Mode!$"
# 843 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 844 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 845 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: But listen.\n"
# 846 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the CHAMPION,\l"
# 847 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 848 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 849 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 850 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 851 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 852 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 853 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 854 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I think I'll take a short break\n"
# 855 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from fieldwork.\p"
# 856 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I think I'll help the PROF here for\n"
# 857 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a while.$"
# 858 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 859 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 860 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: For the time being,\n"
# 861 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm taking a break from fieldwork.\p"
# 862 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll be helping out the PROF here\n"
# 863 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a while.$"
# 864 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 865 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 866 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 867 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your POKéDEX.\p"
# 868 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 869 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 870 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 871 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the HOENN\n"
# 872 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "region's POKéDEX.\p"
# 873 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 874 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 875 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 876 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 877 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare POKéMON only found\n"
# 878 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 879 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 880 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 881 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 882 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 883 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: These are rare POKéMON\n"
# 884 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 885 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 886 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 887 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 888 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 889 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The FIRE POKéMON\n"
# 890 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 891 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 892 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 893 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 894 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 895 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The WATER POKéMON\n"
# 896 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 897 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 898 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 899 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 900 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 901 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The GRASS POKéMON\n"
# 902 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 903 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 904 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 905 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 906 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 907 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Take your time before\n"
# 908 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 909 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable POKéMON.$"
# 910 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 911 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 912 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 913 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: I see!\n"
# 914 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You picked a fine POKéMON!$"
# 915 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 916 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 917 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 918 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from PROF. BIRCH!$"
# 919 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 920 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 921 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 922 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 923 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 926 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 927 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the HOENN POKéDEX,\l"
# 928 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 929 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 930 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 931 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 932 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 933 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 935 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised POKéMON.\n"
# 936 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 937 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 938 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 939 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 940 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 941 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéMON.$"
# 942 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 944 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, after this…\n"
# 945 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 946 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 947 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 948 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 949 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL POKéDEX?\p"
# 950 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the PROF.$"
# 951 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 953 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Rather than collecting\n"
# 954 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON, I prefer slowly and \l"
# 955 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 956 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 957 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 958 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 959 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 960 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 961 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 963 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}!\n"
# 964 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 965 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 966 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 967 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 968 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 969 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 970 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
# 971 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, SCOTT.\p"
# 972 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. TIDAL now.\n"
# 973 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 974 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 975 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 976 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 978 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "at either SLATEPORT or LILYCOVE.\p"
# 979 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 980 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 981 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 982 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 999 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_2
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_1:
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_2:
# 1000 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1001 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_0
# 1002 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1003 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerGetStarter
# 1004 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1005 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1007 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 1008 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_1


# 1013 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerGetStarter:
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1015 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 1015 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 1016 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname::
# 1020 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 1021 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_2
LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_1:
# 1024 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_2:
# 1022 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_1

LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname_4:
# 1025 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	return


LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter::
# 1030 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1031 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_le LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_2
# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_1, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_7
LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_6:
# 1062 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_Text_0
# 1063 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_2:
# 1032 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_4:
# 1066 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_GRASS_STARTER_BALL
# 1067 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_1
# 1068 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 1069 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1070 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname
# 1071 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_5:
# 1036 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	multichoicegrid 10, 3, MULTI_GRASS_STARTERS, 3, 0
# 1037 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	switch VAR_RESULT
# 1038 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_14
# 1040 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_15
# 1042 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_16
# 1044 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 3, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_17
# 1046 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 4, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_18
# 1048 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 5, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_19
# 1050 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 6, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_20
# 1052 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 7, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_21
# 1054 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 8, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_22
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_7:
# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_9
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_9:
# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_3, LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_5
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12:
# 1059 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_4

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_14:
# 1039 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_BULBASAUR
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_15:
# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_CHIKORITA
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_16:
# 1043 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_TREECKO
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_17:
# 1045 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_TURTWIG
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_18:
# 1047 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_SNIVY
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_19:
# 1049 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_CHESPIN
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_20:
# 1051 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_ROWLET
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_21:
# 1053 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_GROOKEY
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_22:
# 1055 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_SPRIGATITO
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_12


LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter::
# 1076 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1077 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_le LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_2
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_1, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_7
LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_6:
# 1108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_Text_0
# 1109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_2:
# 1078 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_4:
# 1112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_FIRE_STARTER_BALL
# 1113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_2
# 1114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 1115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname
# 1117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_5:
# 1082 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	multichoicegrid 10, 3, MULTI_FIRE_STARTERS, 3, 0
# 1083 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	switch VAR_RESULT
# 1084 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_14
# 1086 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_15
# 1088 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_16
# 1090 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 3, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_17
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 4, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_18
# 1094 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 5, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_19
# 1096 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 6, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_20
# 1098 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 7, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_21
# 1100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 8, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_22
	end

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_7:
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_2, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_9
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_9:
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_3, LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_5
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12:
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_4

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_14:
# 1085 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_CHARMANDER
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_15:
# 1087 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_CYNDAQUIL
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_16:
# 1089 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_TORCHIC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_17:
# 1091 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_CHIMCHAR
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_18:
# 1093 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_TEPIG
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_19:
# 1095 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_FENNEKIN
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_20:
# 1097 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_LITTEN
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_21:
# 1099 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_SCORBUNNY
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_22:
# 1101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_FUECOCO
	goto LittlerootTown_ProfessorBirchsLab_EventScript_FireStarter_12


LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter::
# 1122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 1
	goto_if_le LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_2
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_1, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_7
LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_6:
# 1154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_Text_0
# 1155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_2:
# 1124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_4:
# 1158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_WATER_STARTER_BALL
# 1159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_3
# 1160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 1161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_AskNickname
# 1163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_5:
# 1128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	multichoicegrid 10, 3, MULTI_WATER_STARTERS, 3, 0
# 1129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	switch VAR_RESULT
# 1130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_14
# 1132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_15
# 1134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_16
# 1136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 3, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_17
# 1138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 4, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_18
# 1140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 5, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_19
# 1142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 6, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_20
# 1144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 7, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_21
# 1146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	case 8, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_22
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_7:
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_2, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_9
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_9:
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_RECEIVED_STARTER_3, LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_5
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_6

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12:
# 1151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_4

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_14:
# 1131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_SQUIRTLE
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_15:
# 1133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_TOTODILE
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_16:
# 1135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_MUDKIP
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_17:
# 1137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_PIPLUP
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_18:
# 1139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_OSHAWOTT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_19:
# 1141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_FROAKIE
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_20:
# 1143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_POPPLIO
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_21:
# 1145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_SOBBLE
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12

LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_22:
# 1147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SELECTED_STARTER, SPECIES_QUAXLY
	goto LittlerootTown_ProfessorBirchsLab_EventScript_WaterStarter_12


LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter::
# 1168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname 0, VAR_SELECTED_STARTER
# 1169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic VAR_SELECTED_STARTER, 10, 3
# 1170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playmoncry VAR_SELECTED_STARTER, 0
# 1171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_Text_0, MSGBOX_YESNO
# 1172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_1
# 1182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_1:
# 1173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon VAR_SELECTED_STARTER, 5
# 1174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_4:
# 1175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_Text_1
# 1177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	return


LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_0:
# 1001 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ah, you must be {PLAYER}{KUN}!\p"
	.string "I heard you and your family were moving\n"
	.string "in today.\p"
	.string "Please come in!$"

LittlerootTown_ProfessorBirchsLab_EventScript_GrassStarter_Text_0:
# 1062 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Don't take more than one!$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_Text_0:
# 1171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarter_Text_1:
# 1176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} recieved the {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon::
# 1188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet, so...\l"
	.string "I'd like to give you one!\p"
	.string "Please choose one from one of\n"
	.string "the balls on the table next to me.$"

LittlerootTown_ProfessorBirchsLab_Text_WaitStarterPick::
# 1207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Pick whichever starter\n"
	.string "you'd like!$"
