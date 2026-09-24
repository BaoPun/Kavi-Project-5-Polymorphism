# Kavi-Project-5-Polymorphism

This project will have you exercise your ability to use Polymorphism in a classic adventure game called Hunt the Wumpus.  There will be two parts to this project.  The first part requires you to actually make the Hunt the Wumpus game as specified in the **Requirements** section.  The second part will have you utilize a popular path-finding algorithm used in AI called A* search to have the Wumpus chase after the player after each movement around the map.  More on each of these parts can be seen in each of their individual sections.

# Background and Win/Lose Conditions
Traditionally, Hunt the Wumpus is a game where the adventurer is stuck in a maze and their objective is to locate and kill the monster, known as the Wumpus, lurking in the maze.  While there are many variations to the game, one of the main goals is to kill the Wumpus.  However, in this version, there will be additional objectives.  Not only would you need to kill the Wumpus, but you also need to find the hidden treasure of gold located somewhere in the maze and escape the maze safely.  Thus, the following conditions must be satisfied to win the game: kill the Wumpus, retrieve the treasure box full of gold, and escape from the maze from where you started.  Note that there is no sequential order to these objectives, i.e. it is possible to retrieve the gold before killing the Wumpus.  However, you also have a couple of lose conditions: go into a room where the Wumpus is and get eaten or fall into a room with a pit fall and fall to your death.  Finally, note that movement across the maze is restricted to vertical and horizontal directions only; no diagonal directions are allowed.

# Percepts
Percepts are messages indicating that you are adjacent (not diagonally) to a room containing an **Event**.  If you happen to be near an event, a message of some kind should show up on your screen before you input your next direction for movement.  While you do not have to use these exact messages, I recommend you tailor your message for each event as follows:
- Gold -> "You can see a glimmering light nearby"
- Bat -> "You hear some flapping noises from somewhere close"
- Pit -> "You suddenly feel a chilling breeze"
- Wumpus -> "You smell something foul"
- Arrow -> "You see a familiar object nearby"

# Events
As touched upon in the **Percepts** section, there are five events to account for.  Below will discuss each event in greater detail.  The event class should be polymorphic and adjust based on a specific event/room the player is in.

## Gold
There is only one treasure box full of gold in the maze.  When the player walks over to the room containing this treasure box, they will pick it up for themselves.  The gold will not longer show up on the map once picked up by the player.

## Bat
Upon walking into a room full of Bats (there will be multiple), the player is then transported to a random location.  The random location may also be on top of another event, so it's possible to be transported into a room containing the Wumpus, for example, which would result in the player losing on the spot.  

## Pit
Upon walking into a pitfall room, the player normally dies.  However, in this game, the condition for dying upon walking into this room will be set to 80%.  The remaining 20% will let the player survive the fall, but magically end up back in their starting position.  

## Wumpus 
The Wumpus is the main boss in this game, and they are trying to stop the adventurer from retrieving the treasure full of gold.  If the player walks into a room with the Wumpus in it, the player instantly loses.  In part 2, the Wumpus becomes sentient and is always aware of the player's location, and thus will always make a move that will put them closer to the player.

## None
The default event is that there is none.  To emulate polymorphic behavior, a "None" room represents a room that does not contain an Event.  

# Requirements
## Part 1
Implement the Hunt the Wumpus game, as specified in the above sections.  You will be given all the necessary files to complete this task, along with functions in each to help you out.  Importantly, I have done the maze generation for you already in "board.hpp" and "board.cpp", so you do not need to worry about making the maze full of events.  You will also need to figure out what the game loop will look like, but here is a basic outline: show the map, choose an action, choose a movement, trigger an event based on said action.  Repeat the game loop while the player has not won, has not lost, or has not chosen to quit.  

## Part 2
Part 2 requires you to finish part 1 and have a fully functioning game.  I will expand more on this part, but the basic premise is that you will make the Wumpus be sentient by implementing a path finding algorithm from the Wumpus's current location to the player's new location and taking the optimal route based on this.  This part will introduce you to AI, and I will further expand on this part with you in person.

# Video
Below is a video link that demos both part 1 and part 2.

https://oregonstate.zoom.us/rec/play/lRUm_3iHwo7nptw_L3lI_rV_E9PAZgqdZDjYb2k-9cSTEaQMQl2Wu0wtfxg0FcOcz4Toz1Z26vTaojK3.PMSlkQ8Tw_smcne1?accessLevel=meeting&canPlayFromShare=true&from=share_recording_detail&continueMode=true&oldStyle=true&componentName=rec-play&originRequestUrl=https%3A%2F%2Foregonstate.zoom.us%2Frec%2Fshare%2FhuCa5S79sZHBd0qrCCiFdvS4jRmulZaPP1_Eed0yqKNbtH9vZAUuvcVo08E32jwl.0_hsYrBKkzj3TInO

Passcode: +P8PngCq

# Questions
If you have any questions about the project at all, please reach out to me, whether that be by email or by your mom's phone.
