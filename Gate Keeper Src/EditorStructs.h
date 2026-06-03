
#pragma pack(push,1)

// The following are for the internal stuff.

#define TYPE_ARMOR			0
#define TYPE_WEAPON			1
#define TYPE_HELM				2
#define TYPE_AMULET			3
#define TYPE_MISSILE			4
#define TYPE_BELT				5
#define TYPE_RING				6
#define TYPE_SHIELD			7
#define TYPE_BOOT				8
#define TYPE_CLOAK			9
#define TYPE_GLOVE			10
#define TYPE_POTION			11
#define TYPE_WAND				12
#define TYPE_BOOK				13
#define TYPE_SCROLL			14
#define TYPE_MISC				15
#define TYPE_UNKNOWN			16 // When set to this type, user isn't allowed to edit.

#define TYPE_ENDOFLIST		1000

struct KNOWNITEM
{
	// See defines above.
	int	nItemType;

	// This is the code used to store in the data file. "BOW" "AROW" "HELM"
	char	szCode[11];

	// The item number. It gets appended to the code for the data file. "HELM01"
	char	szNumber[5];

	// Description of the item.
	char szDescription[101];

	// Number of items.
	short	nQuantity;

	BOOL	bStackable;

	BOOL	bIndentified;
};

struct ITEMTYPE
{
	char *pszType;
};

struct ITEMPOS
{
	char *pszPos;
};

#define MAX_MEMORIZEDINFO	100

#define ST_PRIEST			0
#define ST_WIZARD			1
#define ST_INNATE			2
#define ST_ENDOFLIST		1000

// An array of these define all the spells that the editor 
// knows about.
struct SPELLDESC
{
	// See above ST_ defines.
	int nSpellType;

	// How the game stores the spell name. "SPWI103"
	char szGameCode[8];

	// Spells actual name for printing.
	char szDescription[51];
};

// This is the maximum number of spells the character can have
// either memorized or known at one time (500 of each).
#define MAX_SPELLS		500

// While a character is being edited all their known
// and memorized spells are converted to this form
// for easy editing.
struct CHARSPELL
{
	// This is an index pointed into the _spells[] array. -1
	// indicates an unused entry.
	int	nSpellDesc;

	// See my descriptions in the SPELL struct for my guess
	// as to the meaning of these.
	short nValue1;
	short nValue2;

	// This is the number of times the spell appears in the memorized list.
	int	nMemorized;

	// This is the "SPWI103" text.
	char	szGameCode[8];

	// 0 = Priest, 1 = Mage, 2 = Innate
	int	nType;
};

struct SEX
{
	char *pszSex;
	unsigned char chSex;
};

struct ALIGNMENT
{
	char *pszAlignment;
	unsigned char chAlignment;
};

struct CLASS
{
	char *pszClass;
	unsigned char chClass;
};

struct RACE
{
	char *pszRace;
	unsigned char chRace;
};

struct MAGESPECIALTY
{
	char *pszSpecialty;
	short nSpecialty;
};

#define NUM_THIEFRACEMOD	7
struct THIEFRACEMOD
{
	int	nPickPockets;
	int	nOpenLocks;
	int	nDetectTraps;
	int	nStealth;
};

#define NUM_THIEFDEXMOD		25
struct THIEFDEXMOD
{
	int	nPickPockets;
	int	nOpenLocks;
	int	nDetectTraps;
	int	nStealth;
};

// An area is an 8x8 grid of 640x480 screens.
#define QUADX		1280
#define QUADY		960

struct MAPINFO
{
	// This is the area code for the game.
	char	*pszArea;

	// True for an area selection, FALSE for locations in that area. Used to
	// group the area with the locations in that area.
	BOOL	bArea;

	// Coordinates of a location in this area.
	short	nX;
	short nY;

	char	*pszDescription;
};

struct RACIALENEMY
{
	char	*pszName;
	unsigned char chValue;
};

struct NUMBEROFATTACKS
{
	char	*pszText;
	unsigned char chValue;
};

#pragma pack(pop)
