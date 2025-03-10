.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 0, 15
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_MAY, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_RED, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_LEAF, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_ETHAN, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_LYRA, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_LUCAS, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_DAWN, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_HILBERT, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_HILDA, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_NATE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_ROSA, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_CALEM, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_SERENA, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_ELIO, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_SELENE, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_VICTOR, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_GLORIA, Route101_EventScript_HideBrendanInBedroom
	call_if_eq VAR_RESULT, STYLE_FLORIAN, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, STYLE_JULIANA, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "HI... HIIIILFE!!!$"

Route101_Text_PleaseHelp:
	.string "HILFE!!! Du dort drüben!\n"
	.string "Bitte! HILFE!!!\p"
	.string "In meinem BEUTEL...\n"
	.string "Da findest du einen POKéBALL!$"

Route101_Text_DontLeaveMe:
	.string "Wo-Wo wi-willst du hin?\n"
	.string "Lass mich nicht im Stich!!!$"

Route101_Text_YouSavedMe:
	.string "PROF. BIRK: Puuuh...\p"
	.string "Ich habe im hohen Gras POKéMON\n"
	.string "studiert, als ich angesprungen wurde.\p"
	.string "Du hast mich gerettet.\n"
	.string "Vielen, vielen Dank!\p"
	.string "Oh?\p"
	.string "Hi, du bist doch {PLAYER}{KUN}!\p"
	.string "Aber dies ist nicht der Ort für ein\n"
	.string "Schwätzchen, komm doch mit \l"
	.string "in mein POKéMON-LABOR, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "Sind deine POKéMON müde, bring sie in\n"
	.string "ein POKéMON-CENTER.\p"
	.string "In ROSALTSTADT, gleich hier um die\n"
	.string "Ecke, gibt es ein POKéMON-CENTER.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wilde POKéMON springen dich in hohem\n"
	.string "Gras gerne an.\p"
	.string "Wenn du POKéMON fangen willst, musst\n"
	.string "du ins hohe Gras gehen und sie suchen.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} ROSALTSTADT$"

Route101_EventScript_Glumanda::
    msgbox Route101_Text_Glumanda, MSGBOX_NPC
    end

Route101_Text_Glumanda:
    .string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein name ist Zauke07!\p"
	.string "Immer wenn du mich am ende einer\n"
	.string "Route Siehst, sprich mich an, denn\l"
	.string "ich habe einen Heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 1 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

