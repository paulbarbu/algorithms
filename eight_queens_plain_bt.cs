using System;

namespace Queens2
{
	class MainClass
	{
		public static int size = 4;
		
		/**
		 * Generate all solutions for the N Queens problem
		 */
		
		public static void Main (string[] args)
		{
			Console.WriteLine("Board dimensions: ");
			size = Convert.ToInt32(Console.ReadLine());
			
			//queens positions will be stored in an array as follows: board[line] = column
			int[] board = new int[size];
			
			//start with no queens on the first line
			bt(0, board);
		}
		
		public static void bt(int queen, int[] board){
			for(int i = 0;i < size;i++){ //try to put the queen on a cloumn
				board[queen] = i; //mark the position: put it on the line "queen", column: "i"
				if(notAttacked(queen, board)){
					
					if(solution(queen)){ //if this is a solution, then display it
						showBoard(size, board, true);
					}
					else{ //try another queen one line under the last one
						bt(queen+1, board);
					}
				}
			}
		}
		
		public static bool notAttacked(int queen, int[] board){
			for(int i=0;i<queen;i++){ //check the queens already set
				//deductions from a bi-dimensional array to a single dimension array 
				if(board[i] == board[queen] || Math.Abs(board[i] - board[queen]) == queen - i){
					return false;
				}
			}
			
			return true;
		}
		
		public static bool solution(int queen){
			if(queen == size-1){ //if all the queens are on the table this is a solution
				return true;
			}
			
			return false;
		}
		
		public static void showBoard(int size, int[] board, bool map){
			if(map){ //display the board as a map
				for(int i=0;i<size;i++){
					for(int j=0;j<size;j++){
						if(board[i] == j){
							Console.Write("1 ");
						}
						else{
							Console.Write("0 ");
						}
					}
					Console.Write("\n");
				}
				Console.Write("\n");
			}
			else{ //or display just the columns
				for(int i=0;i<size;i++){
					Console.WriteLine(board[i]);
				}
				Console.WriteLine("\n");
			}
		}
		
	}
}

