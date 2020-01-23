#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Island.h"
#include "MyStack.h"
#include "MyQueue.h"

class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
   Island* islandArr;
   int arrSize;
   char** fName;
   int fSize;
   int fTop;
   
  
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
 ArchipelagoExpedition()
 {
     islandArr = new Island[11];
     arrSize = 11;
     fName = new char*[2];
     fSize = 2;
     fTop = 0;
 }
    
 //Destructor
 ~ArchipelagoExpedition()
 {
     delete[](fName);
     delete[](islandArr);
 }
  
  
 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \r\n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
//       exit(1);
      return;
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();
    else if ( strcmp (command, "s") == 0)
      doShortestPath();
    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  s <int1> <int2> \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 //Conducts a breadth first search on the island given
 bool bfs(int b, MyQueue &islandQueue)
 {
     while (!islandQueue.isEmpty())
     {
         int a = islandQueue.getTop();
         islandQueue.pop();
         for(int i = 0; i < islandArr[a].numEdges(); ++i)
         {
             int c = islandArr[a].getEdgeAt(i);
             if(!islandArr[c].getVisited())
             {
                 islandArr[c].setPrev(a);
                 if(c == b)
                     return true;
                 islandQueue.insert(c);
             }
         }         
     }
     return false;
 }
 //BFS helper. Takes in PBR value of pathList to prevent destructor from being called inside the function
 MyStack breadthFirstSearch(int x, int y, MyStack& pathList)
 {
     for(int i = 1; i < arrSize; ++i)
     {
         islandArr[i].setPrev(-1);
     }
     MyQueue islandQueue;
     islandQueue.insert(x);
     if(bfs(y, islandQueue) == false)
     {
         printf("You can NOT get from island %d to island %d in one or more ferry rides\n", x, y);
     }
     else
     {
         printf("You can get from island %d to island %d in one or more ferry rides by path: ", x, y);
         int currentIsland = y;
         pathList.insert(currentIsland);
         do{
             currentIsland = islandArr[currentIsland].getPrev();
             pathList.insert(currentIsland);
         } while(currentIsland != x);
     }
 }
    
    
 void doShortestPath()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
     
   if(val1 > arrSize - 1 || val2 > arrSize - 1 || val1 < 0 || val2 < 0)
   {
       printf("Out of range\n");
       return;
   }
     
   printf("Getting shortest path\n");
   MyStack pathList = breadthFirstSearch (val1, val2, pathList);
   if(!pathList.isEmpty())
       pathList.show();
   printf("\n");
     
 }
 //DFS function
 bool dfs(int a, int b)
 {
     for(int i = 0; i < islandArr[a].numEdges(); ++i)
     {
         int c = islandArr[a].getEdgeAt(i);
         if( c == b)
             return true;
         if(!islandArr[c].getVisited())
         {
             islandArr[c].setVisited(true);
             if(dfs(c,b) == true)
                 return true;
         }
     }
     return false;
 }
//Helper function
void dfsHelper(int x, int y)
{
    for(int i = 1; i < arrSize; ++i)
    {
        islandArr[i].setVisited(false);
    }
    if(dfs(x,y))
        printf("You can get from island %d to island %d in one or more ferry rides\n", x, y);
    else
        printf("You can NOT get from island %d to island %d in one or more ferry rides\n", x, y);
}
    
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
     
   if(val1 > arrSize - 1 || val2 > arrSize - 1 || val1 < 0 || val2 < 0)
   {
       printf("Out of range\n");
       return;
   }
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);
   //Performs dfs search
   dfsHelper(val1, val2);
   
 }
 
 void doResize()
 {
   int val1 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
     
   if(val1 < 1)
   {
       printf("Value must be greater than 0\n");
       return;
   }
       

   printf ("Performing the Resize Command with %d\n", val1 );
   //Deletes old dynamic array
   delete(islandArr);
   //Creates new array
   this->islandArr = new Island[val1 + 1];
   //Sets size to proper amount
   this->arrSize = val1 + 1;
 

 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");

   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
     
   //Checks if out of range
   if(val1 > arrSize - 1 || val2 > arrSize - 1 || val1 < 0 || val2 < 0)
   {
       printf("Out of range\n");
       return;
   }
   //inserts Edge
   islandArr[val1].addEdge(val2);

 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   /// get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");

   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   printf("%s\n", next);
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
     
   //Check if out of range
   if(val1 > arrSize - 1 || val2 > arrSize - 1 || val1 < 0 || val2 < 0)
   {
       printf("Out of range\n");
       return;
   }
   //Deletes edge
   islandArr[val1].delEdge(val2);
 }
 
 //Lists all islands and connections
 void doList()
 {
    //Displays connected islands
   for(int i = 1; i < arrSize; ++i)
   {
       if(!islandArr[i].isEmpty())
       {
           printf("Island %d is connected to islands ", i);
           islandArr[i].showInfo();
       }
       else
       {
           printf("Island %d is not connected to any islands", i);
       }
        printf("\n");
   }
 }
 
 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   printf("*%s*\n", fname);
   FILE* tmpFile = fopen(fname, "r");
   if(tmpFile == NULL)
   {
       printf("File not found\n");
       return;
   }
       
     
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns
   
   //Check if already in array, returns if already in
   for(int i = 0; i < fTop; i++)
     {
         if(strcmp(fname, fName[i]) == 0)
          {
              printf("IN ARRAY \n");
              return;
          }
      }
      
     //Grows dynamic array if array is full
      if(fTop >= fSize)
      {
          char** tmp = fName;
          fName = new char*[fSize+2];
          for(int i = 0; i < fSize; ++i)
          {
              fName[i] = tmp[i];
          }
          fSize += 2;
          delete(tmp);
      }
     //Creates new string and adds to dynamic array
      char* tmp = new char;
      printf("Adding to index %d\n", fTop);
      strcpy(tmp, fname);
      fName[fTop] = tmp;
      fTop += 1;
     
     //Calls recursively on new file
     this->processCommandLoop(tmpFile);
     fclose(tmpFile);
     //Deletes the file in the list
     for(int i = 0; i < fTop; i++)
     {
         if(strcmp(fname, fName[i]) == 0)
          {
              delete(fName[i]);
              fName[i] = NULL;
              return;
          }
      }
     
    
 }
};

int main (int argc, char** argv)
{



  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }