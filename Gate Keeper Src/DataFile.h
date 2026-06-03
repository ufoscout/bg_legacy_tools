
#pragma pack(push,1)

///////////////////////////////////////////////////////////////////////
// The .gam file is built thus...
//
// FILE_HEADER - Contains the number of characters in the party. There
//    is an NPC_INFO block following the header for each character in
//		the party.
//	NPC_INFO - Variable number of items. Number is in FILE_HEADER.
// <NPC Data> - There is one of these blocks of data for every NPC_INFO
//		block above. The lengths of the blocks are in NPC_INFO. The start
//		of each block is also contained in the NPC_INFO struct. See below
//		for the format of the NPC data.
// NPC_INFO - Variable number of items. This section is pointed to in
//    the header. 
// <NPC Data> - For each of the blocks above there is an NPC record
//		just like there was for the characters in the party. The last
//		record has some extra data at the end. Not sure what it is for.
//		The extra data is accounted for in the INFO block by the size,
//		it just doesn't conform to how I understand the data to work.
// QUEST - Variable number of items. Header has a count and a start of
//		this.
// MYSTERY - Dunno what these represent. Like the other items, they are
//		kept track of in the header.
//
///////////////////////////////////////////////////////////////////////

// Proficiencies are packed 3 bits each. Hi 3 bits is the 1st class of a
// dual class character.
#define HITRIBBLE(byte)				((unsigned char)((byte >> 3) & 0x07))
#define LOTRIBBLE(byte)				((unsigned char)(byte & 0x07))
#define MAKETRIBBLE(loTrib,hiTrib)	((unsigned char)((hiTrib << 3) | (loTrib & 0x07)))

// This is at the beginning of the save game file.
struct FILE_HEADER
{
	char	junk[0x18];

	// Gold, shared in the party.
	UINT	nGold;

	char	junk6[0x04];

	// Offset to the first NPC_INFO record for members of the party.
	UINT	nPartyOffset;

	// Number of characters in the party.
	UINT	nPartyCount;

	char junk2[0x08];

	// Offset to the data immediately following the last
	// in party character data.
	UINT	nNonPartyCharOffset;

	// This is the number of NPC_INFO blocks that nAfterChars points to.
	UINT	nNonPartyCharCount;

	// Offset to the part of the file that appears to have information
	// on what quest have been done.
	UINT	nQuestOffset;

	// Number of QUEST item;
	UINT	nQuestCount;

	char junk4[0x10];

	// Not sure what this data is.
	UINT	nMysteryOffset;

	// Number of mystery items.
	UINT	nMysteryCount;

	char	junk5[0x5C];
};

struct QUEST
{
	char junk[0x54];
};

// Follows immediately after the FILE_HEADER. There is one of these
// blocks of data for each character in the party.
struct NPC_INFO
{
	char	junk[0x02];

	// This is what number you are in line in the party. First character
	// is position 0.  For character NOT in the party this value is 0xFFFF.
	short	nPartyPosition;

	// This is the position in the data file the character data starts
	// at.
	UINT	nDataStart;

	// How many bytes of data the character record takes up.
	UINT	nDataLen;

	char	junk3[0x0C];

	// Area the character is in. "AR3400"
	char	szArea[8];

	// Position in the area of the character.
	unsigned short	nPlayerX;
	unsigned short nPlayerY;

	// The viewing rectangle's postion.
	unsigned short nViewX;
	unsigned short nViewY;

	char	junk2[0x98];

	// In the case of the first character (PC) this is the name of the
	// character. The name is NOT found in the character data portion
	// like it is for an NPC.
	char	szName[21];

	char  junk4[0x8B];
};

////////////////////////////////////////////////////////////////////
// Definition of a NPC
//
// NPC_HEADER
// SPELL (known) - Variable number of these records. The number
//		appearing is in the header.
// NPC_MEMORIZEDINFO - Variable number of blocks. 
// SPELL (set to memorize) - Variable number of these records the
//		number appearing is in the header.
// NPC_ITEMSLOTS
// ITEM - Variable number of these records. The number appearing is
//		in the header.
//
////////////////////////////////////////////////////////////////////

struct SPELL
{
	// First two letters are always SP.
	// Next 2 describe what type of spell. WI=wizard,IN=Innate?,PR=Priest
	// Next 1 is the spell level.
	// Next 2 are an ordinal indicating which spell.
	char	szSpell[8];

	// For memorized spells, 1 seems to mean the spell is currently available.
	// For known spells it appears to be the SpellLevel-1. This seems a bit
	// odd since the name of the spell has the spell level in it too, but it
	// seems to be consistent. On a mage it controls what page of his spell
	// book the spell shows up in. You can make level 2 spells appare on the
	// level 1 page.
	short nValue1;

	// Memorized Area: I don't know what this represents in the memorized area.
	// some spells are marked 0x4141 or 0x4100 but I don't know why.
	// Known Area: 0 = Priest, 1 = Mage, 2 = Innate, 3 = crashy crashy
	short nValue2;
};

struct ITEM
{
	// NULL terminated string. Last 2 digits are always a number identifying the
	// item in that class. Left of the digits to the beginning are the class of
	// the item.  "BOW01", "HELM12"
	char szItem[10];

	// Number of the item you carry.
	short nCount;

	char junk[4];

	// Looks like it is 1 if the item is identified.
	short nIdentified;

	char nJunk[2];
};

#define RACE_NOTHING				0
#define RACE_HUMAN				1
#define RACE_ELF					2
#define RACE_HALFELF				3
#define RACE_DWARF				4
#define RACE_HALFLING			5
#define RACE_GNOME				6

#define AVATAR_RACE_HUMAN		0x00
#define AVATAR_RACE_ELF			0x01
#define AVATAR_RACE_HALFELF	0x01
#define AVATAR_RACE_GNOME		0x02
#define AVATAR_RACE_HALFLING	0x03
#define AVATAR_RACE_DWARF		0x02

#define AVATAR_SEX_MALE			0x00
#define AVATAR_SEX_FEMALE		0x10

#define SEX_NOTHING				0
#define SEX_MALE					1
#define SEX_FEMALE				2
#define SEX_OTHER					3

#define CLASS_NOTHING				0
#define CLASS_MAGE					1
#define CLASS_FIGHTER				2
#define CLASS_CLERIC					3
#define CLASS_THIEF					4
#define CLASS_BARD					5
#define CLASS_PALADIN				6	
#define CLASS_FIGHTERMAGE			7
#define CLASS_FIGHTERCLERIC		8
#define CLASS_FIGHTERTHIEF			9
#define CLASS_FIGHTERMAGETHIEF	10
#define CLASS_DRUID					11
#define CLASS_RANGER					12
#define CLASS_MAGETHIEF				13
#define CLASS_CLERICMAGE			14
#define CLASS_CLERICTHIEF			15
#define CLASS_FIGHTERDRUID			16
#define CLASS_FIGHTERMAGECLERIC	17
#define CLASS_CLERICRANGER			18

#define MAGE_ABJURER					0x0040
#define MAGE_CONJURER				0x0080
#define MAGE_DIVINER					0x0100
#define MAGE_ENCHANTER				0x0200
#define MAGE_ILLUSIONIST			0x0400
#define MAGE_INVOKER					0x0800
#define MAGE_NECROMANCER			0x1000
#define MAGE_TRANSMUTER				0x2000
#define MAGE_MAGE						0x4000	// Set when normal mage.

#define ALIGN_LAWFULGOOD			0x11
#define ALIGN_NEUTRALGOOD			0x21
#define ALIGN_CHAOTICGOOD			0x31
#define ALIGN_LAWFULNEUTRAL		0x12
#define ALIGN_TRUENEUTRAL			0x22
#define ALIGN_CHAOTICNEUTRAL		0x32
#define ALIGN_LAWFULEVIL			0x13
#define ALIGN_NEUTRALEVIL			0x23
#define ALIGN_CHAOTICEVIL			0x33

#define RACIAL_ENEMY_CRAWLER		0x68
#define RACIAL_ENEMY_ETTERCAP		0x6B
#define RACIAL_ENEMY_GHOUL			0x6C
#define RACIAL_ENEMY_GIBBERLING	0x6D
#define RACIAL_ENEMY_GNOLL			0x6E
#define RACIAL_ENEMY_HOBGOBLIN	0x6F
#define RACIAL_ENEMY_KOBOLD		0x70
#define RACIAL_ENEMY_OGRE			0x71
#define RACIAL_ENEMY_SKELETON		0x73
#define RACIAL_ENEMY_SPIDER		0x74

struct NPC_HEADER
{
	char sVersion[0x10];

	// Fighter = 00
	// Dual Fighter/Mage = 08
	// Multi Fighter/Mage = 00
	// Multi Fighter/Druid = 05
	// Multi Fighter/Thief = 00
	// Above are examples I pulled from several save files. Anything 8 or greateer
	// marks the character as dual class. I don't know what the number means other
	// than using it as a flag for dual class.
	char chDualClass;

	char junk8[0x07];

	// Experience points.
	UINT nExperience;

	// Apparently only used when the character is not in the party.
	UINT nGold;

	char junk17[0x04];

	unsigned short nCurrentHp;
	unsigned short nMaxHp;

	// Race and sex graphic used in the game.
	// High nibble is sex, low is race.
	unsigned char chAvatar;

	// Low nibble is the class. The high nibble I'm not completely sure
	// of the use for. When 6 it appears to mean it is a walking character.
	// When 4, it's sitting and drinking. I haven't experimented much
	// with it because it crashes the game with invalid values (time consuming).
	unsigned char chAvatarClass;

	char junk14[0x1E];

	unsigned char chAC;

	char junk20[0x09];

	unsigned char chThac0;
	unsigned char chNumberOfAttacks;

	unsigned char chSavePPD;		// Paralyze/Poison/Death
	unsigned char chSaveRSW;		// Rod/Staff/Wand
	unsigned char chSavePP;			// Petrify/Polymorph
	unsigned char chSaveBW;			// Breath Weapons
	unsigned char chSaveS;			// Spells

	char junk18[0x04];

	unsigned char chMagicResist;

	char junk16[0x08];

	// This is the value in the .CHR file. When you import the value
	// doesn't seem to stick though. If you reload a saved game after
	// importing the value seems to drop back to where it should be.
	// Editing this value in Baldur.gam doesn't seem to have an effect.
	unsigned char chLore;

	unsigned char chOpenLocks;
	unsigned char chStealth;
	unsigned char chFindTraps;
	unsigned char chPickPockets;

	char junk10[0x03];

	// These are broken down into 3 bit entities (gonna call them tribbles).
	// The left most 2 bits are ignored as far as I know. The hi tribble is
	// the value of the 1st class of a dual class character. Use the macros
	// at the head of the file to manipulate the tribbles.
	unsigned char chProfLargeSword;
	unsigned char chProfSmallSword;
	unsigned char chProfBow;
	unsigned char chProfSpear;
	unsigned char chProfBlunt;
	unsigned char chProfSpiked;
	unsigned char chProfAxe;
	unsigned char chProfMissile;

	char junk[0x1BE];

	// One byte for each class you have.
	unsigned char chLevel[3];

	char junk9;

	unsigned char chStr;
	unsigned char chStrBonus;
	unsigned char chInt;
	unsigned char chWis;
	unsigned char chDex;
	unsigned char chCon;
	unsigned char chCha;

	char junk21[0x02];

	unsigned char chRacialEnemy;

	char junk19[0x04];

	short nMageSpecialty;

	char junk2[0x2A];

	// See defines above.
	unsigned char chRace;

	unsigned char chClass;

	char junk13;

	unsigned char chSex;

	char junk15[0x05];

	// 2 Nibbles, each is 1-3, 1 = goodness, 2 = nuetral, 3 = baddy
	// 13 = Lawful Evil. Defines are above.
	unsigned char chAlignment;

	char junk12[0x04];

	// Character's name.
	char szName[21];

	char junk6[0x0B];

	// This is the number of bytes after the header that the known spell list
	// starts at.
	int nKnownOffset;

	// Number of spells/special abilities the character knows about. This is NOT
	// the memorized list.
	int nKnownSpells;

	// Number of bytes from the header that the between spell data starts.
	int nMemorizedInfoOffset;

	// Number of blocks that happen between the known and memorized spells. Each
	// block is 16 bytes.
	int nMemorizedInfo;

	// Number of bytes from the header that the memorized spells start at.
	int nMemorizedOffset;

	// Number of spells or skills the character has set to memorize.
	int nMemorizedSpells;

	// Number of bytes from the header where the item slot struct is.
	int nItemSlotOffset;

	// Number of bytes from the start of the header is where the EQ list starts.
	int nItemOffset;

	// Number of items carried.
	int nItems;

	// Number of bytes after the header that the after items start.
	int nAfterItemsOffset;

	// Number of AFTER_ITEM blocks. I think they are temporary things that
	// effect the character. When a bard spell is on, the person gets 2
	// of these blocks appended.
	int nAfterItems;

	char junk4[0x8];
};

struct NPC_AFTERITEM
{
	char junk[0x30];
};

// 
struct NPC_MEMORIZEDINFO
{
	// This looks like it is the spell level-1.
	short nSpellLevel;

	// Number of spells I am able to memorize, not necessarily the same as the number
	// I have SET to be memorized. Both of these seem to stay the same even when I
	// put on a ring of wizardy which doubled the amount of 1st level spells my 
	// wizard could use.
	short nCanMemorize1;
	short nCanMemorize2;

	// Same as all the other spell types I think. 0 = Priest, 1 = Wiz, 2 = Innate
	short nSpellType;

	short nValue1[0x02];

	// Appears to be the number of spells memorized for this spell level.
	short nNumMemorized;

	short nValue2;
};

#define NUM_ITEM_SLOTS		38
struct NPC_ITEMSLOTS
{
	// There seems to be 38 item slots in the file, although, I don't count that
	// many looking at the character's inventory. Each item here is set either to
	// 0xFFFF which means the slot is empty, or it has an ordinal that gives the
	// index of the item description. The item descriptions follow this block of
	// data.  There are as many item descriptions as nItems indicates.
	unsigned short nItemSlot[NUM_ITEM_SLOTS];

	// No idea what this is for. Most often it is: E8 03 00 00
	char junk[4];
};

// This is found at the head of an exported character (.chr) file.
struct CHR_HEADER
{
	char sVersion[8];

	char szName[21];

	char junk[0x0B];

	// Where the NPC_HEADER info starts.
	UINT nDataStart;

	// Total length of the character.
	UINT nDataLen;

	char junk2[0x34];
};

#pragma pack(pop)
