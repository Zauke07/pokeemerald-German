MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	pokemartlistend

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "Es gibt Items, die den Status eines\n"
	.string "Pokémon kurzzeitig erhöhen.\p"
	.string "Ich weiß, dass man X-ANGRIFF und\n"
	.string "X-VERTEIDIGUNG im Kampf einsetzen\l"
	.string "kann…\p"
	.string "Ich glaube, es gibt aber auch noch\n"
	.string "andere.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "Setze eine bestimmte Attacke ein,\n"
	.string "oder stattdessen ein Item…\p"
	.string "Ich glaube, die Entscheidungen des\n"
	.string "TRAINERs bestimmen, wie ein Kampf\l"
	.string "verläuft.$"

