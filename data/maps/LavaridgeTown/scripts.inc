.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
    lockall
    call Common_EventScript_SetupRivalMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_MAY, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_RED, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LEAF, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_ETHAN, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LYRA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LUCAS, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_DAWN, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_HILBERT, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_HILDA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_NATE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_ROSA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_CALEM, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_SERENA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_ELIO, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_SELENE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_VICTOR, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_GLORIA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_JULIANA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "{RIVAL}: {PLAYER}{KUN}! Lange nicht gesehen!\p"
	.string "Oh? Während ich die heißen Quellen\n"
	.string "besuchte, hast du den Bad Lavastadt\n"
	.string "ARENA-ORDEN bekommen.\p"
	.string "Du musst gute POKéMON gesammelt\n"
	.string "haben…\l"
	.string "Nein, ich glaube, du hast einige\n"
	.string "aufgezogen.\p"
	.string "Ich denke, es wäre in Ordnung, wenn\n"
	.string "du das hier hättest.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "{RIVAL}: Mit diesen GO-GOGGLES wirst\n"
	.string "du keine Probleme haben, durch die Wüste\n"
	.string "in der Nähe von ROUTE 111 zu kommen.\p"
	.string "Aber, wow, {PLAYER}{KUN}…\n"
	.string "Arenen herausfordern…\p"
	.string "Du gibst dir Mühe, weil du nicht gegen\n"
	.string "mich verlieren willst, wetten!\p"
	.string "{PLAYER}{KUN}, ich denke, ich sollte deinen\n"
	.string "Vadda in der ARENA von Blütenburg City\n"
	.string "herausfordern.\p"
	.string "Bis bald!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "{RIVAL}: {PLAYER}, hey, es ist eine Weile\n"
	.string "her. Wie läuft's?\p"
	.string "Hmm…\n"
	.string "Das ist eine anständige Sammlung von\n"
	.string "ORDEN.\p"
	.string "Na gut.\n"
	.string "Du kannst das hier genauso gut haben.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "{RIVAL}: Behalte die bei dir, wenn du\n"
	.string "vorhast, in die Wüste in der Nähe von\n"
	.string "ROUTE 111 zu gehen.\p"
	.string "Es sollte einige POKéMON geben, die\n"
	.string "ausschließlich in der Wüste leben.\l"
	.string "Du könntest nach diesen suchen.\p"
	.string "Was mich betrifft…\n"
	.string "Ich überlege, dein Vadda herauszufordern,\l"
	.string "den ARENALEITER von Blütenburg City.\p"
	.string "Im Gegensatz zu dir, {PLAYER}, sieht dein\n"
	.string "Vater wirklich stark aus.\p"
	.string "Bis dann!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Ich habe hier ein EI.\p"
	.string "Ich hatte gehofft, es durch Bedecken\n"
	.string "mit heißem Sand bei den heißen Quellen\l"
	.string "auszubrüten. Aber das scheint nicht\l"
	.string "auszureichen…\p"
	.string "Ich habe gehört, es wäre am besten,\n"
	.string "wenn es zusammen mit POKéMON\l"
	.string "getragen würde.\p"
	.string "Du bist ein TRAINER, ja?\n"
	.string "Und deine POKéMON strahlen Vitalität aus.\p"
	.string "Also, was sagst du?\n"
	.string "Wirst du dieses EI ausbrüten?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Gut! Ich hoffe, du wirst viel mit diesem\n"
	.string "EI herumlaufen!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} hat das EI erhalten.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? Du hast zu viele POKéMON.\n"
	.string "Es gibt keinen Platz für dieses EI…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Wie du willst…\p"
	.string "Wenn du deine Meinung änderst und\n"
	.string "dieses EI ausbrüten möchtest, werde\n"
	.string "ich hier sein.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Hin und wieder wird ein EI in der\n"
	.string "POKéMON-PENSION gefunden.\p"
	.string "Zumindest besagt das das Gerücht.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Wir entnehmen so viel heißes Wasser,\n"
	.string "wie wir brauchen, und doch versiegen\n"
	.string "die heißen Quellen nie.\p"
	.string "Ist das nicht magisch?\p"
	.string "Diese heißen Quellen entstehen in der\n"
	.string "Nähe aktiver Vulkane. Wasseradern\n"
	.string "unter der Erde werden durch Magma\n"
	.string "erhitzt und steigen als heiße Quellen\n"
	.string "auf.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "In diesem heißen Sand vergraben zu\n"
	.string "sein ist… Seufz…\p"
	.string "So warm und himmlisch…\p"
	.string "Eh? Gyaah! Autsch!\p"
	.string "Ein POKéMON hat mir in den Hintern\n"
	.string "gebissen!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, du magst heiße Quellen, oder?\p"
	.string "Das ist überraschend für jemanden\n"
	.string "so jung wie dich.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Ich bade jeden Tag in den heißen\n"
	.string "Quellen.\p"
	.string "Ich möchte eine schöne und starke\n"
	.string "ARENALEITERIN wie Flavia werden.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Wenn Leute POKéMON in heiße Quellen\n"
	.string "setzen, könnte das wirklich seltsam\n"
	.string "sein.\p"
	.string "Warum, es könnte ein elektrisches Bad,\n"
	.string "ein Sprudelbad oder sogar ein\n"
	.string "Lava-Bad sein…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Sie behaupten, dass diese heißen\n"
	.string "Quellen gut sind, um nervöse\n"
	.string "Anspannung zu beruhigen, schmerzende\n"
	.string "Muskeln zu lindern, romantische\n"
	.string "Probleme zu lösen und Geld anzuziehen…$"

LavaridgeTown_Text_TownSign:
	.string "Bad Lavastadt\p"
	.string "“POKéMON CENTER HEIßE QUELLEN\n"
	.string "Ein ausgezeichneter Ort zum Entspannen!”$"

LavaridgeTown_Text_GymSign:
	.string "Bad Lavastadt POKéMON-ARENA\n"
	.string "LEITERIN: Flavia\l"
	.string "“Eine mit einer feurigen Leidenschaft, die\n"
	.string "brennt!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON-KRÄUTERLADEN\n"
	.string "“Bitterer Geschmack--bessere Heilung!”$"

