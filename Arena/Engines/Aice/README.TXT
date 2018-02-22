AICE version 0.99.2
Copyright (c) 2004-2006 by Anastasios Milikas (milix).
Co-author for this version: Christos Boussios.
e-mail: aice@in.gr

This is a beta release of AICE chess engine that played in Mainz 2006 Chess960 WCC.
AICE works with chess GUIs that support the x-board or UCI protocols, like Winboard, 
Arena, Fritz8 (ChessBase).


****************
IMPORTAND NOTICE
****************

IF YOU FIND ANY BUG IN AICE (LIKE ILLEGAL MOVE OR CRASH OR TIME LOSS) PLEASE SUBMIT 
THE 'AICE.LOG' FILE AND ANY DEBUG FILE THAT THE GUI HAD GENERATED TO THE AUTHOR AT 
aice@in.gr


WINBOARD INSTALLATION
---------------------

Assuming that you have installed AICE in the folder c:\chess\engines\aice
you can run AICE with Winboard by either starting Winboard from a command
box (A) or editing winboard.ini (B)
 
A. COMMAND LINE
   Start Winboard with AICE by entering the following command in a command box:
      winboard -cp -fcp aice -fd "c:\chess\engines\aice"

B. EDIT WINBOARD.INI
   You can edit the Winboard.ini located in your Winboard installation folder
   (normally C:\Program Files\Winboard) and add the AICE to its engines list. 
   You have to append the line:
       aice -fd "c:\chess\engines\aice"
   after the /firstChessProgramNames statement and the line
       aice -sd "c:\chess\engines\aice"
   after the /secondChessProgramNames statement, so your
   winboard.ini file might look like this:

       /firstChessProgramNames={GNUChess,
       "GNUChes5 xboard"
       aice -fd "c:\chess\engines\aice"
       }

       /secondChessProgramNames={GNUChess,
       "GNUChes5 xboard"
       aice -sd "c:\chess\engines\aice"
       }


ARENA INSTALLATION
------------------
From the main menu select "Engines" and "New engine". A dialog box appears that 
prompts you to select the communication protocol. AICE works with both Winboard 
and UCI protocols. For example, select "Winboard" and click "Ok". 
A new dialog box appears that prompts you to select the engine's executable. 
Browse and find the aice.exe in the AICE's installation folder and click "Open". 


FRITZ INSTALLATION
-------------------
From the main menu select "Engine" and "Create UCI engine". A dialog box appears.
Click the "Browse" button and locate the aice.exe in AICE's installation folder.
Click "OK".


XBOARD (LINUX)
--------------
Assuming that you have installed AICE in the folder /chess/engines/aice
you can start AICE with XBoard on a Linux machine by typing in a xterm:
    xboard -fcp ./aice -fd /chess/engines/aice


*********
COPYRIGHT
*********

This software (SOFTWARE) is protected by copyright law, which states that this 
product (source code and data) cannot be used commercially in any way without 
the permission of the copyright holder. You have the legal right to use this 
software. You only own the licence to use the software - not the software itself.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Anastasios Milikas (milix).
