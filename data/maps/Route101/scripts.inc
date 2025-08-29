# 1 "data/maps/Route101/scripts.pory"

# 2 "data/maps/Route101/scripts.pory"
Route101_MapScripts::
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 4 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 5 "data/maps/Route101/scripts.pory"
	.byte 0
# 6 "data/maps/Route101/scripts.pory"

# 7 "data/maps/Route101/scripts.pory"
Route101_OnTransition:
# 8 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 9 "data/maps/Route101/scripts.pory"
	end
# 10 "data/maps/Route101/scripts.pory"

# 11 "data/maps/Route101/scripts.pory"
Route101_OnFrame:
# 12 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 13 "data/maps/Route101/scripts.pory"
	.2byte 0
# 14 "data/maps/Route101/scripts.pory"

# 15 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 16 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 17 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 18 "data/maps/Route101/scripts.pory"
	end
# 19 "data/maps/Route101/scripts.pory"

# 20 "data/maps/Route101/scripts.pory"

# 21 "data/maps/Route101/scripts.pory"

# 22 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 23 "data/maps/Route101/scripts.pory"
	lockall
# 24 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 25 "data/maps/Route101/scripts.pory"
	closemessage
# 26 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 27 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route101/scripts.pory"
	releaseall
# 29 "data/maps/Route101/scripts.pory"
	end
# 30 "data/maps/Route101/scripts.pory"

# 31 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 32 "data/maps/Route101/scripts.pory"
	lockall
# 33 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 34 "data/maps/Route101/scripts.pory"
	closemessage
# 35 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 36 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route101/scripts.pory"
	releaseall
# 38 "data/maps/Route101/scripts.pory"
	end
# 39 "data/maps/Route101/scripts.pory"

# 40 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 41 "data/maps/Route101/scripts.pory"
	lockall
# 42 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 43 "data/maps/Route101/scripts.pory"
	closemessage
# 44 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 45 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 46 "data/maps/Route101/scripts.pory"
	releaseall
# 47 "data/maps/Route101/scripts.pory"
	end
# 48 "data/maps/Route101/scripts.pory"

# 49 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 50 "data/maps/Route101/scripts.pory"
	walk_up
# 51 "data/maps/Route101/scripts.pory"
	step_end
# 52 "data/maps/Route101/scripts.pory"

# 53 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 54 "data/maps/Route101/scripts.pory"
	walk_right
# 55 "data/maps/Route101/scripts.pory"
	step_end
# 56 "data/maps/Route101/scripts.pory"

# 57 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 58 "data/maps/Route101/scripts.pory"
	walk_down
# 59 "data/maps/Route101/scripts.pory"
	step_end
# 60 "data/maps/Route101/scripts.pory"

# 61 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 62 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 63 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 64 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 65 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 66 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 67 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 68 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 69 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 70 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 71 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 72 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 73 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 74 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 75 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 76 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 77 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 78 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 79 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 80 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 81 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 82 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 83 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 84 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 85 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 86 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 87 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 88 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 89 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 90 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 91 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 92 "data/maps/Route101/scripts.pory"
	step_end
# 93 "data/maps/Route101/scripts.pory"

# 94 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 95 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 96 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 97 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 98 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 99 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 100 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 101 "data/maps/Route101/scripts.pory"
	step_end
# 102 "data/maps/Route101/scripts.pory"

# 103 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 104 "data/maps/Route101/scripts.pory"
	step_end
# 105 "data/maps/Route101/scripts.pory"

# 106 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 107 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 108 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 109 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 110 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 111 "data/maps/Route101/scripts.pory"
	step_end
# 112 "data/maps/Route101/scripts.pory"

# 113 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 116 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 117 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 118 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 119 "data/maps/Route101/scripts.pory"
	step_end
# 120 "data/maps/Route101/scripts.pory"

# 121 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 122 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 123 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 124 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 127 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 128 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 129 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 130 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 131 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 132 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 133 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 134 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 135 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 136 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 137 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 138 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 139 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 140 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 141 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 146 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 147 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 148 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 149 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 150 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 151 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route101/scripts.pory"
	step_end
# 153 "data/maps/Route101/scripts.pory"

# 154 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 155 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 156 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 159 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 160 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 161 "data/maps/Route101/scripts.pory"
	step_end
# 162 "data/maps/Route101/scripts.pory"

# 163 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 164 "data/maps/Route101/scripts.pory"
	step_end
# 165 "data/maps/Route101/scripts.pory"

# 166 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 167 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 168 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 169 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 170 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 171 "data/maps/Route101/scripts.pory"
	step_end
# 172 "data/maps/Route101/scripts.pory"

# 173 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 174 "data/maps/Route101/scripts.pory"
	walk_up
# 175 "data/maps/Route101/scripts.pory"
	walk_up
# 176 "data/maps/Route101/scripts.pory"
	step_end
# 177 "data/maps/Route101/scripts.pory"

# 178 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 179 "data/maps/Route101/scripts.pory"
	walk_up
# 180 "data/maps/Route101/scripts.pory"
	walk_left
# 181 "data/maps/Route101/scripts.pory"
	walk_up
# 182 "data/maps/Route101/scripts.pory"
	step_end
# 183 "data/maps/Route101/scripts.pory"

# 184 "data/maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 185 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 186 "data/maps/Route101/scripts.pory"
	end
# 187 "data/maps/Route101/scripts.pory"

# 188 "data/maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 189 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 190 "data/maps/Route101/scripts.pory"
	end
# 191 "data/maps/Route101/scripts.pory"

# 192 "data/maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 193 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 194 "data/maps/Route101/scripts.pory"
	end
# 195 "data/maps/Route101/scripts.pory"

# 196 "data/maps/Route101/scripts.pory"

# 197 "data/maps/Route101/scripts.pory"

# 198 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 199 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 200 "data/maps/Route101/scripts.pory"
	return
# 201 "data/maps/Route101/scripts.pory"

# 202 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 203 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 204 "data/maps/Route101/scripts.pory"
	return
# 205 "data/maps/Route101/scripts.pory"

# 206 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 207 "data/maps/Route101/scripts.pory"
	walk_right
# 208 "data/maps/Route101/scripts.pory"
	step_end
# 209 "data/maps/Route101/scripts.pory"

# 210 "data/maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 211 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"
# 212 "data/maps/Route101/scripts.pory"

# 213 "data/maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 214 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 215 "data/maps/Route101/scripts.pory"
	.string "Please! Help!\p"
# 216 "data/maps/Route101/scripts.pory"
	.string "In my BAG!\n"
# 217 "data/maps/Route101/scripts.pory"
	.string "There's a POKé BALL!$"
# 218 "data/maps/Route101/scripts.pory"

# 219 "data/maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 220 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 221 "data/maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 222 "data/maps/Route101/scripts.pory"

# 223 "data/maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 224 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 225 "data/maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 226 "data/maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 227 "data/maps/Route101/scripts.pory"
	.string "You saved me.\n"
# 228 "data/maps/Route101/scripts.pory"
	.string "Thanks a lot!\p"
# 229 "data/maps/Route101/scripts.pory"
	.string "Oh?\p"
# 230 "data/maps/Route101/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 231 "data/maps/Route101/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 232 "data/maps/Route101/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 233 "data/maps/Route101/scripts.pory"

# 234 "data/maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 235 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 236 "data/maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 237 "data/maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 238 "data/maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 239 "data/maps/Route101/scripts.pory"

# 240 "data/maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 241 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 242 "data/maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 243 "data/maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 244 "data/maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 245 "data/maps/Route101/scripts.pory"

# 246 "data/maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 247 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 248 "data/maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
