Gatekeeper
==========

Something to keep in mind while using Gatekeeper: Just because the editor
allows you to edit something doesn't mean the game will like it. Spells and
innate abilities are a good example of this. The format of the files allows
for an huge amount of them. The game, however, doesn't seem to like it when
you give yourself huge amounts of them. You can also set more spells as being
memorized than can be displayed on a page of your spellbook. Whether this
causes any problems in the game I really don't know. The moral is use caution
and maybe even some common sense where applicable when editing.

Back up your games before editing. It is very easy to do. Save the game under
a different name and don't edit that one. If something goes wrong and you
aren't able to undo whatever you did, you can always reload that backup game.

Below are some of the areas I've had email questions about.

=========================
Basic Usage - Saved Games
=========================

1) In the editor choose File|Open Saved Game (or Ctrl+O) and pick a saved game
from the list. There is a radio button that allows you to switch between
viewing single and multi-player games.

2) Make whatever changes you want.

3) Choose File|Save (or Ctrl+S) to save your changes.

4) Go to Baldur's Gate and load the saved game you just finished editing.

======================================
Basic Usage - Exported Character Files
======================================

1) In Baldur's Gate display your character record. One of the buttons on that
screen is EXPORT. Push the EXPORT button and pick a filename to save the
character under.

2) In Gatekeeper chose File|Open Exported Character (or Ctrl+E) and pick a
character to edit.

3) Make whatever changes you want.

3) Choose File|Save (or Ctrl+S) to save your changes.

4) Go back to Baldur's Gate and import the character. If you are a playing a
multiplayer game you can import into your party. If you are playing a single
player game you can only import the character by starting a new game.

==================
Main Editor Screen
==================

Along the top of this screen is a row of six buttons. Each button is for a
potential member of your party. Push the button of whatever party member it is
you want to edit. 

Hold Shift down and click a name button to change the name. You can only change
the name of player characters.

Taking up a major portion of the screen is the character's inventory. There is
a line in the list for each equipment position. To add an item double click
the line or highlight it and press the Edit button. The dialog that pops up
allows you to pick from a list of known items. You can filter the list by 
checking or unchecking the boxes below the list. Items that are stackable or
have charges will allow you to edit the quantity. It is normal to have a 
quantity of 0 for items that are not stackable.

The "Set All Qty" button sets quantity of all the stackable items in your
inventory. Charges and missiles are set to 10,000 while potions are set to 20.
Potions actually have weight so setting the quantity of potions very high just
overloads your characters.

=================
Magical Abilities
=================
Here you can add spells to your books or give yourself innate abilities. Some
caution is advised here. The files can hold more data than the game it seems.
Before the Baldur's Gate patch the game didn't appear to care. After the
patch it is more sensitive to having learned a particular spell or innate 
ability a large number of times.

Magic Type: This chooses the types of spells you see in the lists below. You
can give priest spells to a mage or mage spells to a priest if you really 
want to. You won't be able to see the spells in the game and I don't know if
this will cause any problems, but it can be done. I'd recommend not doing it.

Level: Spell level of the Magic Type chosen. Innate abilities have only level
one. Wizard spells go up to level 9 in the player files but for now, as far as
I'm aware, there are only spells through level 5 in teh game. Priest spells
go up to level 7, but as with Mages, only through level 5 are actually present
in the game.

Can Memorize: This is how many open spell slots you have in your book that you
can assign a spell to be memorized. You can assing more spells here than will
fit on a page in your spellbook, but again, I don't know if this will cause
you any grief in the game.

Memorized: This box is grayed out (not editable). It is simply a total of all
the spells you have set to be memorized. It does get saved to the player file
and I have no idea if a huge number of spells here will cause any problems.

Available Spells: These are all the spells the editor knows about for the 
current Magic Type and Level. Double clicking an item here, or highlighting
and item and pushing the Down Arrow button moves the spell into the Known
Spells list.

Known Spells: These are the spells you know of (ones in your book). Or for
innate abilities they will show up when you push the button on the main game
screen. The "Mem" column is how many times you have the spell memorized. 
Double click an item to set how many times you have it memorized. To remove
a spell from the list use the Up Arrow button.

Memorize All: This button sets all the spells in the Known List to be
memorized a number of times. If you want them all memorized the same number of
times this is a bit easier than double clicking each item in the list.

=========================
Repairing Corrupted Files
=========================

There is now a button labeled "Repair" on the Open Game dialog. Pushing this
button with a game highlighted will make an attempt to analyze the saved game
and repair any problems it can find.

There have been a few cases of corrupted games. I don't know what caused it.
Version 1.08 and up should be able to detect this case of corruption and
stop you from saving. The problem is it is putting in the save file that you
have more spells memorized than you actually do. This creates a some extra
space in the file that shouldn't be there.

Like I said, it should not let you corrupt games like this anymore. I don't
know if the problem is gone since I don't know what caused it. You'll get a
message saying: "Unable to properly recreate the spell data." If you see this
message send me some email and let me know what you were doing at the time.

You will know this happened if you have a game that has been previously save
with Gatekeeper but now won't load. Most likely you'll get the error message
"Unknown spell type."

If you are told your inventory is too full you'll need to clear up a few spots
for it to continue. In Baldur's Gate spread your items out a bit between
characters, or drop some on the ground and resave the game. Then try to repair
again in Gatekeeper.

If you get any messages about your inventory being repaired you'll have to go
into Baldur's Gate after it's done and rearrange your inventory. When it 
reconstructs your inventory it just takes the items in the order it finds them
and drops them into the first available slot. This will lead to things like
swords on your head, boots on your fingers, etc... Pick them up and drop them
where they go (unless you like dressing like this).

When you repair a file Gatekeeper will make a backup of your saved game called
"Baldur.bak." If you need to UNDO the repairs, delete "Baldur.gam" and replace
it with "Baldur.bak." 

==============================================================================
Web:   http://www.mud-master.com/gatekeeper
Ftp:   ftp.mud-master.com
Email: bg@mud-master.com
==============================================================================
