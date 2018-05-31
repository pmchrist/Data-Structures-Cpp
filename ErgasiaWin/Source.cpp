//Libraries
#include <fstream>
#include <string>
#include <vector>
//Time_Management_Library
/*
#include <chrono>
#include <iostream>
*/
//Paralalyzing
/*
#include <thread>
*/

//Used_Functions
//Print_Tree_From_Top_To_Left(Prints_Drawing_Instructions-Used_For_Debugging)
/*
void PrintTree(const std::vector<Node_Main> Vector, int ID) {
	//Go_To_Leftest_SubTree_Then_Go_Up
	std::cout << "\n";
	std::cout << Vector[ID].Value << std::endl;
	if (Vector[ID].LChildID != -1) PrintTree(Vector, Vector[ID].LChildID); else std::cout << -1 << std::endl;
	if (Vector[ID].RChildID != -1) PrintTree(Vector, Vector[ID].RChildID); else std::cout << -1 << std::endl;
	std::cout << "LVLUP\n";
}
*/
//Counting_Execution_Time(Based_On_Object_Scope)
/*
struct Timer {
	//Declaring_Start_Values
	std::chrono::time_point<std::chrono::steady_clock> Start, End;
	std::chrono::duration<float> Duration;
	//Creating_Object_Will_Start_Count
	Timer() {
		Start = std::chrono::high_resolution_clock::now();
	}
	//Deleating_Object_Will_Show_Execution_Time
	~Timer() {
		End = std::chrono::high_resolution_clock::now();
		Duration = End - Start;
		float Time = Duration.count();
		std::cout << "Process_Took:_" << Time << "_sec" << std::endl;
		std::cin.get();
	}
};
*/
//QuickSort
void quickSort(int* Arr, int L, int H)
{
	//Setting_Start_Variables
	int i = L;
	int j = H;
	int pivot = Arr[(i + j) / 2];
	int temp;
	//Recursive_Sorting
	while (i <= j)
	{
		while (Arr[i] < pivot)
			i++;
		while (Arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
			i++;
			j--;
		}
	}
	if (j > L)
		quickSort(Arr, L, j);
	if (i < H)
		quickSort(Arr, i, H);
}
//Custom_Modulus(To_Cover_Possible_Negative_Values_From_%)
int mod(int A, int B) {
	return ((A %= B) < 0) ? A + B :A;
}


//Array_Logic
namespace Array
{
	//Class_For_Main_Array
	class myArr
	{
	public:
		//Basic_Parameters
		int Value;
		//Vector_Of_Neighbours
		std::vector<int> Edges;
		myArr (int V)
			:Value(V)
		{}

		//Modified_Functions_For_Array_Of_Edges
		//Binary_Search
		int Search(int& Value) {
			int L = 0;
			int R = Edges.size() - 1;
			int Mid;
			while (L <= R)
			{
				//Setting_Middle
				Mid = L + (R - L) / 2;
				//If_Value_At_Middle
				if (Edges[Mid] == Value)
					return Mid;
				//If_Bigger_Go_Right_Else_Left
				if (Edges[Mid] < Value)
					L = Mid + 1;
				else
					R = Mid - 1;
			}
			//No_Value_Found
			return -1;
		}
		void Insert(int& Value) {
			//Setting_Start_Parameters
			int L = 0;
			int R = Edges.size() - 1;
			int Mid;
			//Binary_Search
			while (L <= R)
			{
				//Setting_Middle
				Mid = L + (R - L) / 2;
				//If_Value_At_Middle
				if (Edges[Mid] == Value)
					//If_Value_Exists_Return
					return;
				//If_Bigger_Go_Right_Else_Left
				if (Edges[Mid] < Value)
					L = Mid + 1;
				else
					R = Mid - 1;
			}
			//If_No_Value_Found_Insert_It_In_Right_Position(So_That_We_Have_Sorted_Array)
			Edges.insert(Edges.begin() + L, Value);
		}
		void Delete(int& Value) {
			int ID = Search(Value);
			if (ID != -1) {
				//Delete_At_Index
				Edges.erase(Edges.begin() + ID);
			}
		}
		//Returns_Number_Of_Neighbours
		/*
		void Print_Number_Edges(std::ofstream& output) {
			output << Edges.size() << std::endl;
		}
		*/
		//Prints_All_Neighbours
		void Print_Edges(std::ofstream& output) {
			//Printing
			for (int i = 0; i < Edges.size(); i++) {
				output << Edges[i] << " ";
			}
			output << std::endl;
		}
	};
	//Binary_Search
	int Search(std::vector<myArr>& Vector, int Value){
		//Setting_Start_Variables
		int L = 0;
		int R = Vector.size() - 1;
		int Mid;
		while (L <= R)
		{
			//Setting_Middle
			Mid = L + (R - L) / 2;
			//If_Value_At_Middle
			if (Vector[Mid].Value == Value)
				return Mid;
			//If_Bigger_Go_Right_Else_Left
			if (Vector[Mid].Value < Value)
				L = Mid + 1;
			else
				R = Mid - 1;
		}
		//No_Value_Found
		return -1;
	}
	int Insert(std::vector<myArr>& Vector, int& Value) {
		int L = 0;
		int R = Vector.size() - 1;
		int Mid;
		//Binary_Search
		while (L <= R)
		{
			//Setting_Middle
			Mid = L + (R - L) / 2;
			//If_Value_At_Middle
			if (Vector[Mid].Value == Value)
				return Mid;
			//If_Bigger_Go_Right_Else_Left
			if (Vector[Mid].Value < Value)
				L = Mid + 1;
			else
				R = Mid - 1;
		}
		//If_No_Value_Found_Create_It_And_Insert_It_In_Right_Position
		myArr Temp(Value);
		Vector.insert(Vector.begin() + L, Temp);
		//Return_Insert_ID
		return L;
	}
	//Iterative_DFS
	void Print_Number_Edges(std::ofstream& output, std::vector<myArr>& Vector) {
		//Declaring_Start_Variables
		int Size = Vector.size();
		std::vector<int> queue;
		queue.reserve(Size);
		int Trees = 0, Value, ID;
		//Setting_Array_For_Visited_Nodes
		bool* arrBool = new bool[Size];
		for (int b = 0; b < Size; b++) {
			arrBool[b] = false;
		}
		//Starting_Counting
		for (int i = 0; i < Size; i++) {
			//If_Visited_Continue
			if (arrBool[i]) continue;
			else {
				//Set_Value_To_Visited_And_Push_All_Of_Its_Neighbours_To_Queue_To_Visit_In_Future
				arrBool[i] = true;
				queue.insert(queue.end(), Vector[i].Edges.begin(), Vector[i].Edges.end());
				//Working_With_Queue
				while (!queue.empty()) {
					//Work_With_Last_Value_From_Queue
					Value = queue.back();
					ID = Search(Vector, Value);
					if (arrBool[ID]) queue.pop_back();
					else {
						arrBool[ID] = true;
						queue.pop_back();
						queue.insert(queue.end(), Vector[ID].Edges.begin(), Vector[ID].Edges.end());
					}
				}
			}
			//We_Have_Visited_Whole_Tree_Go_To_Next
			Trees += 1;
		}
		output << Trees << std::endl;
	}
	//Recursive_DFS(Creates_Function_Call_Stack_Overflow_With_>1000000_Nodes)
	/*
	//Iterator
	void Iterator(bool* arrBool, std::vector<myArr>& Vector, int startID) {
		for (int i = 0; i < Vector[startID].Edges.size(); i++) {
			int ID = Search(Vector, Vector[startID].Edges[i]);
			if (!arrBool[ID]) {
				arrBool[ID] = true;
				Iterator(arrBool, Vector, ID);
			}
		}
	}
	//Main
	void Print_Number_Edges(std::ofstream& output, std::vector<myArr>& Vector) {
		//Setting_Start_alues
		int Size = Vector.size();
		bool* arrBool = new bool[Size];
		int Trees = 0;
		for (int i = 0; i < Size; i++) arrBool[i] = false;
		//Starting_Search
		for (int j = 0; j < Size; j++) {
			//If_We_Counted_It
			if (arrBool[j]) continue;
			else arrBool[j] = true;
			Trees += 1;
			Iterator(arrBool, Vector, j);
		}
		output << Trees << std::endl;
	}
	*/
}


//AVLtree_Logic
namespace Tree
{
	//AVLtree_Classes
	//Basic_Node_Logic
	class Node
	{
	public:
		int Value;
		int Weight = 0;
		int Height = 1;
		int ParentID;
		int LChildID = -1;
		int RChildID = -1;

		Node(int Value, int Parent = -1)
			:Value(Value), ParentID(Parent)
		{}
	};
	//Main_Tree_Node_Logic
	class Node_Main : public Node
	{
	public:
		std::vector<Node> Edges;
		int EdgesTopID = -1;

		Node_Main(int Value, int Parent = -1)
			:Node(Value, Parent)
		{}
		//Returns_Number_Of_Neighbours
		/*
		void Print_Number_Edges(std::ofstream& output) const {
			output << Edges.size() << std::endl;
		}
		*/
		//InOrder_Print_Of_Tree
		void Print_Edges(std::ofstream& output, int CurrentID) const {
			if (CurrentID == -1) return;
			//Getting_Left_SubTree
			Print_Edges(output, Edges[CurrentID].LChildID);
			//Printing
			output << Edges[CurrentID].Value << ' ';
			//Getting_Right_SubTree
			Print_Edges(output, Edges[CurrentID].RChildID);
		}
	};
	
	//Templates_Are_Compatible_Only_With_Tree::Node_Classes
	//AVLtree_SubCommands
	//Getting_Tree_Depth_Recursive(Used_For_Debugging)
	/*
	template <typename T>
	int Tree_Depth(const std::vector<T>& Vector, int CurrentID) {
		if (CurrentID == -1) return 0;
		int ld = Tree_Depth(Vector, Vector[CurrentID].LChildID);
		int rd = Tree_Depth(Vector, Vector[CurrentID].RChildID);
		if (ld > rd) return (ld + 1); else return (rd + 1);
	}
	*/
	//Updating_Weight+Height
	template <typename T>
	void Upd_Param(std::vector<T>& Vector, int CurrentID) {
		//If_Error_Occured
		if (CurrentID == -1) return;
		//If_It_Is_Bottom_Leaf_Continue
		if (Vector[CurrentID].Height == 1) Upd_Param(Vector, Vector[CurrentID].ParentID);
		//Setting_Start_Values
		int R, L;
		int OriginalHeight = Vector[CurrentID].Height;
		//Setting_Height_To_The_Highest_Of_Children+1
		if (Vector[CurrentID].RChildID == -1) R = 0;
		else R = Vector[Vector[CurrentID].RChildID].Height;
		if (Vector[CurrentID].LChildID == -1) L = 0;
		else L = Vector[Vector[CurrentID].LChildID].Height;
		(R > L) ? Vector[CurrentID].Height = R + 1 : Vector[CurrentID].Height = L + 1;
		//Counting_Weight
		Vector[CurrentID].Weight = R - L;
		//No_Need_To_Update_If_Height_Update_Or_No_Updates_In_Place
		if (Vector[CurrentID].Weight > 1 || Vector[CurrentID].Weight < -1) return;
		if (OriginalHeight == Vector[CurrentID].Height) return;
		//Continue
		if (Vector[CurrentID].ParentID != -1) Upd_Param(Vector, Vector[CurrentID].ParentID);
	}
	//Right_Rotation_Procedure
	template <typename T>
	void Rotate_Right(std::vector<T>& Vector, int CurrentID) {
		//Saving_Values
		//Original_Parent_Value
		int Parent = Vector[CurrentID].ParentID;
		//Original_Child_Value
		int Child = Vector[CurrentID].LChildID;
		//If_There_Is_Child_We_Need_To_Update_More_Values
		if (Child != -1) {
			//Original_Child_Child_Value
			int Childish = Vector[Child].RChildID;
			//Changing_Values_Of_Previous_Child
			Vector[Child].ParentID = Parent;
			Vector[Child].RChildID = CurrentID;
			//Changing_Parent_Child
			Vector[CurrentID].LChildID = Childish;
			//Telling_RChild_Of_Child_About_New_Parent
			if (Childish != -1) {
				Vector[Childish].ParentID = CurrentID;
			}
		}
		//Changing_Values_Of_Previous_Parent
		Vector[CurrentID].ParentID = Child;
		//Telling_Parent_About_Child_Change
		if (Parent != -1) {
			if (CurrentID == Vector[Parent].RChildID) {
				Vector[Parent].RChildID = Child;
			}
			else {
				Vector[Parent].LChildID = Child;
			}
		}
		//Node_Parameters_Update
		Upd_Param(Vector, CurrentID);
	}
	//Mirror_Procedure_For_Left_Rotation
	template <typename T>
	void Rotate_Left(std::vector<T>& Vector, int CurrentID)	{
		//Saving_Values
		//Original_Parent_Value
		int Parent = Vector[CurrentID].ParentID;
		//Original_Child_Value
		int Child = Vector[CurrentID].RChildID;
		//If_There_Is_Child_We_Need_To_Update_More_Values
		if (Child != -1) {
			//Original_Child_Child_Value
			int Childish = Vector[Child].LChildID;
			//Changing_Values_Of_Previous_Child
			Vector[Child].ParentID = Parent;
			Vector[Child].LChildID = CurrentID;
			//Changing_Parent_Child
			Vector[CurrentID].RChildID = Childish;
			//Telling_RChild_Of_Child_About_New_Parent
			if (Childish != -1) {
				Vector[Childish].ParentID = CurrentID;
			}
		}
		//Changing_Values_Of_Previous_Parent
		Vector[CurrentID].ParentID = Child;
		//Telling_Parent_About_Child_Change
		if (Parent != -1) {
			if (CurrentID == Vector[Parent].LChildID) {
				Vector[Parent].LChildID = Child;
			}
			else {
				Vector[Parent].RChildID = Child;
			}
		}
		//Node_Parameters_Update
		Upd_Param(Vector, CurrentID);
	}
	//Rotation_Manager
	template <typename T>
	void Rotate(std::vector<T>& Vector, int& Top, int CurrentID) {
		//There_Are_Four_Possible_Scenarios_For_Rotation
		if (Vector[CurrentID].Weight > 1) {
			if (Vector[Vector[CurrentID].RChildID].Weight < 0) {
				//Necessary_Rotation_Applied
				Rotate_Right(Vector, Vector[CurrentID].RChildID);
				Rotate_Left(Vector, CurrentID);
				//Updating_Top_If_Needed
				if (Vector[CurrentID].ParentID != -1) {
					if (Vector[Vector[CurrentID].ParentID].ParentID == -1) {
						Top = Vector[CurrentID].ParentID;
					}
				}
			}
			else {
				//Necessary_Rotation_Applied
				Rotate_Left(Vector, CurrentID);
				//Updating_Top_If_Needed
				if (Vector[CurrentID].ParentID != -1) {
					if (Vector[Vector[CurrentID].ParentID].ParentID == -1) {
						Top = Vector[CurrentID].ParentID;
					}
				}
			}
		}
		else {
			if (Vector[CurrentID].Weight < -1) {
				if (Vector[Vector[CurrentID].LChildID].Weight > 0) {
					//Necessary_Rotation_Applied
					Rotate_Left(Vector, Vector[CurrentID].LChildID);
					Rotate_Right(Vector, CurrentID);
					//Updating_Top_If_Needed
					if (Vector[CurrentID].ParentID != -1) {
						if (Vector[Vector[CurrentID].ParentID].ParentID == -1) {
							Top = Vector[CurrentID].ParentID;
						}
					}
				}
				else {
					//Necessary_Rotation_Applied
					Rotate_Right(Vector, CurrentID);
					//Updating_Top_If_Needed
					if (Vector[CurrentID].ParentID != -1) {
						if (Vector[Vector[CurrentID].ParentID].ParentID == -1) {
							Top = Vector[CurrentID].ParentID;
						}
					}
				}
			}
		}
	}
	
	//AVLtree_MainCommands
	template <typename T>
	int Insert(std::vector<T>& Vector, int& Top, const int& X)	{
		//If_Vector_Is_Empty
		if (Vector.empty()) {
			Vector.emplace_back(X);
			Top = 0;
			return 0;
		}
		//Set_Start_Point
		int CurrentID = Top;
		bool Searching = true;
		//While_CurrentNode_Is_Not_Target_Node - Integrate_Search_Function
		while (Searching)
		{
			//If_Value_Already_Exists_Terminate
			if (Vector[CurrentID].Value == X) return CurrentID;
			//If_Bigger_Go_To_Right
			if (Vector[CurrentID].Value < X) {
				//If_There_Is_No_RChild
				if (Vector[CurrentID].RChildID == -1) {
					//Create_RChild+Update_RChild+Update_CurrentNode
					Vector.emplace_back(X, CurrentID);
					Vector[CurrentID].RChildID = Vector.size() - 1;
					CurrentID = Vector.size() - 1;
					Searching = false;
				}
				//If_There_Is_Child_Update_CurrentNode_And_Continue
				else {
					CurrentID = Vector[CurrentID].RChildID;
				}
			}
			//Same_For_LChild
			else {
				//If_There_Is_No_LChild
				if (Vector[CurrentID].LChildID == -1) {
					//Create_RChild+Update_RChild+Update_CurrentNode
					Vector.emplace_back(X, CurrentID);
					Vector[CurrentID].LChildID = Vector.size() - 1;
					CurrentID = Vector.size() - 1;
					Searching = false;
				}
				//If_There_Is_Child_Update_CurrentNode_And_Continue
				else {
					CurrentID = Vector[CurrentID].LChildID;
				}
			}
		}
		int OriginalID = CurrentID;
		//Weight_Update
		Upd_Param(Vector, CurrentID);
		//Applying_Rotation
		while (CurrentID != -1) {
			if (Vector[CurrentID].Weight < -1 || Vector[CurrentID].Weight > 1) {
				Rotate(Vector, Top, CurrentID);
				break;
			}
			CurrentID = Vector[CurrentID].ParentID;
		}
		return OriginalID;
	};
	template <typename T>
	int Search(const std::vector<T>& Vector, const int& Top, const int& X) {
		//Checking_If_Container_Isn't_Empty
		if (Vector.empty()) return -1;
		//Set_Start_Point
		int CurrentID = Top;
		//Let's_Search
		while (1)
		{
			//If_Value_Exists_Return_It
			if (Vector[CurrentID].Value == X) return CurrentID;
			//If_Bigger_Go_To_Right
			if (Vector[CurrentID].Value < X) {
				//If_There_Is_No_RChild
				if (Vector[CurrentID].RChildID == -1) {
					//No_Value_In_Tree
					return -1;
				}
				//If_There_Is_Child_Update_CurrentNode_And_Continue
				else {
					CurrentID = Vector[CurrentID].RChildID;
				}
			}
			//Same_For_LChild
			else {
				//No_Value_In_Tree
				if (Vector[CurrentID].LChildID == -1) {
					return -1;
				}
				//If_There_Is_Child_Update_CurrentNode_And_Continue
				else {
					CurrentID = Vector[CurrentID].LChildID;
				}
			}
		}
	};
	template <typename T>
	void Delete(std::vector<T>& Vector, int& Top, int X, int SubTop = -1) {
		//Checking_If_Container_Isn't_Empty
		if (Vector.empty()) return;
		//Setting_Top
		//We_Need_SubTop_For_Faster_And_Correct_Removing_Node_With_Two_Children
		if (SubTop == -1) SubTop = Top;
		//Checking_If_We_Have_This_Value
		int CurrentID = Search(Vector, SubTop, X);
		//Deleting
		if (CurrentID != -1) {
			//Saving_Value
			int OriginalID = CurrentID;
			//When_Value_Has_No_Children
			if (Vector[CurrentID].LChildID == -1 && Vector[CurrentID].RChildID == -1) {
				//We_Will_Perform_Swap_With_Last_Element_And_Delete_It
				//Update_Parent
				if (Vector[CurrentID].ParentID != -1) {
					if (Vector[Vector[CurrentID].ParentID].RChildID == CurrentID) {
						Vector[Vector[CurrentID].ParentID].RChildID = -1;
					}
					else {
						Vector[Vector[CurrentID].ParentID].LChildID = -1;
					}
				}
				//We_Are_Deleting_Last_Element
				else {
					Vector.clear();
					Top = -1;
					return;
				}
				//Swapping_With_Last_(If_It_Isn't_Already_Last_Otherwise_The_Terrible_Bug)
				if (CurrentID != Vector.size() - 1) {
					Vector[CurrentID] = Vector[Vector.size() - 1];
					//Updating_Parent_Of_Last
					if (Vector[Vector.size() - 1].ParentID != -1) {
						//If_Object_Is_RChild
						if (Vector[Vector[Vector.size() - 1].ParentID].RChildID == Vector.size() - 1) {
							Vector[Vector[Vector.size() - 1].ParentID].RChildID = CurrentID;
						}
						//Object_Is_LChild
						else {
							Vector[Vector[Vector.size() - 1].ParentID].LChildID = CurrentID;
						}
					}
					//Update_Top_If_Needed_(If_We_Will_PopUp_Last_Object_We_Need_To_Update_Top)
					else {
						Top = CurrentID;
					}
					//Updating_Children_Of_Last_(There_Is_A_Weird_Collision_When_We_Have_Children_As_Parent)
					if (Vector[Vector.size() - 1].LChildID != -1) {
						Vector[Vector[Vector.size() - 1].LChildID].ParentID = CurrentID;
					}
					if (Vector[Vector.size() - 1].RChildID != -1) {
						Vector[Vector[Vector.size() - 1].RChildID].ParentID = CurrentID;
					}
				}
				//Weight_Update
				Upd_Param(Vector, CurrentID);
				//Applying_Rotation
				while (CurrentID != -1) {
					if (Vector[CurrentID].Weight < -1 || Vector[CurrentID].Weight>1) Rotate(Vector, Top, CurrentID);
					CurrentID = Vector[CurrentID].ParentID;
				}
				//Deleting
				Vector.pop_back();
				//If_New_Value==-1_We_Got_New_Top
				if (CurrentID < Vector.size()) {
					if (Vector[CurrentID].ParentID == -1) {
						Top = CurrentID;
					}
				}
				return;
			}
			//When_Value_Has_LChild
			if (Vector[CurrentID].LChildID != -1 && Vector[CurrentID].RChildID == -1) {
				//We_Will_Perform_Swap_With_Last_Element_And_Delete_It
				//Update_Parent
				if (Vector[CurrentID].ParentID != -1) {
					if (Vector[Vector[CurrentID].ParentID].RChildID == CurrentID) {
						Vector[Vector[CurrentID].ParentID].RChildID = Vector[CurrentID].LChildID;
					}
					else {
						Vector[Vector[CurrentID].ParentID].LChildID = Vector[CurrentID].LChildID;
					}
				}
				else {
					//Deleting_Top_Setting_New_One
					Top = Vector[CurrentID].LChildID;
				}
				//Update_Child_(It's_Here_Because_It_Got_Conflicts_With_Previous_Top_Update)
				Vector[Vector[CurrentID].LChildID].ParentID = Vector[CurrentID].ParentID;
				//Swapping_With_Last_(If_It_Isn't_Already_Last_Otherwise_The_Terrible_Bug)
				if (CurrentID != Vector.size() - 1) {
					//Swap_Values
					Vector[CurrentID] = Vector[Vector.size() - 1];
					//Updating_Parent_Of_Last
					if (Vector[Vector.size() - 1].ParentID != -1) {
						//If_Object_Is_RChild
						if (Vector[Vector[Vector.size() - 1].ParentID].RChildID == Vector.size() - 1) {
							Vector[Vector[Vector.size() - 1].ParentID].RChildID = CurrentID;
						}
						//Object_Is_LChild
						else {
							Vector[Vector[Vector.size() - 1].ParentID].LChildID = CurrentID;
						}
					}
					//Update_Top_If_Needed_(If_We_Will_PopUp_Last_Object_We_Need_To_Update_Top)
					else {
						Top = CurrentID;
					}
					//Updating_Children_Of_Last_(There_Is_A_Weird_Collision_When_We_Have_Children_As_Parent)
					if (Vector[Vector.size() - 1].LChildID != -1) {
						Vector[Vector[Vector.size() - 1].LChildID].ParentID = CurrentID;
					}
					if (Vector[Vector.size() - 1].RChildID != -1) {
						Vector[Vector[Vector.size() - 1].RChildID].ParentID = CurrentID;
					}
				}
				//Weight_Update
				Upd_Param(Vector, CurrentID);
				//Applying_Rotation
				while (CurrentID != -1) {
					if (Vector[CurrentID].Weight < -1 || Vector[CurrentID].Weight>1) Rotate(Vector, Top, CurrentID);
					CurrentID = Vector[CurrentID].ParentID;
				}
				//Deleting
				Vector.pop_back();
				//If_New_Value==-1_We_Got_New_Top
				if (CurrentID < Vector.size()) {
					if (Vector[CurrentID].ParentID == -1) {
						Top = CurrentID;
					}
				}
				return;
			}
			//When_Value_Has_RChild
			if (Vector[CurrentID].LChildID == -1 && Vector[CurrentID].RChildID != -1) {
				//We_Will_Perform_Swap_With_Last_Element_And_Delete_It
				//Update_Parent
				if (Vector[CurrentID].ParentID != -1) {
					if (Vector[Vector[CurrentID].ParentID].RChildID == CurrentID) {
						Vector[Vector[CurrentID].ParentID].RChildID = Vector[CurrentID].RChildID;
					}
					else {
						Vector[Vector[CurrentID].ParentID].LChildID = Vector[CurrentID].RChildID;
					}
				}
				else {
					Top = Vector[CurrentID].RChildID;
				}
				//Update_Child_(It's_Here_Because_It_Got_Conflicts_With_Previous_Top_Update)
				Vector[Vector[CurrentID].RChildID].ParentID = Vector[CurrentID].ParentID;
				if (Vector[Vector[CurrentID].RChildID].ParentID == -1) {
					Top = Vector[CurrentID].RChildID;
				}
				//Swapping_With_Last_(If_It_Isn't_Already_Last:_Otherwise_The_Terrible_Bug)
				if (CurrentID != Vector.size() - 1) {
					//Swap_Values
					Vector[CurrentID] = Vector[Vector.size() - 1];
					//Updating_Parent_Of_Last
					if (Vector[Vector.size() - 1].ParentID != -1) {
						//If_Object_Is_RChild
						if (Vector[Vector[Vector.size() - 1].ParentID].RChildID == Vector.size() - 1) {
							Vector[Vector[Vector.size() - 1].ParentID].RChildID = CurrentID;
						}
						//Object_Is_LChild
						else {
							Vector[Vector[Vector.size() - 1].ParentID].LChildID = CurrentID;
						}
					}
					//Update_Top_If_Needed_(If_We_Will_PopUp_Last_Object_We_Need_To_Update_Top)
					else {
						Top = CurrentID;
					}
					//Updating_Children_Of_Last_(There_Is_A_Weird_Collision_When_We_Have_Children_As_Parent)
					if (Vector[Vector.size() - 1].LChildID != -1) {
						Vector[Vector[Vector.size() - 1].LChildID].ParentID = CurrentID;
					}
					if (Vector[Vector.size() - 1].RChildID != -1) {
						Vector[Vector[Vector.size() - 1].RChildID].ParentID = CurrentID;
					}
				}
				//Weight_Update
				Upd_Param(Vector, CurrentID);
				//Applying_Rotation
				while (CurrentID != -1) {
					if (Vector[CurrentID].Weight < -1 || Vector[CurrentID].Weight>1) Rotate(Vector, Top, CurrentID);
					CurrentID = Vector[CurrentID].ParentID;
				}
				//Deleting
				Vector.pop_back();
				//If_New_Value==-1_We_Got_New_Top
				if (CurrentID < Vector.size()) {
					if (Vector[CurrentID].ParentID == -1) {
						Top = CurrentID;
					}
				}
				return;
			}
			//When_Value_Has_Two_Children
			if (Vector[CurrentID].LChildID != -1 && Vector[CurrentID].RChildID != -1) {
				//Update_CurrentID_With_Smallest_Value_From_Right_SubTree
				CurrentID = Vector[CurrentID].RChildID;
				while (Vector[CurrentID].LChildID != -1)
				{
					CurrentID = Vector[CurrentID].LChildID;
				}
				//Swap
				Vector[OriginalID].Value = Vector[CurrentID].Value;
				//Delete_Duplicate
				Tree::Delete(Vector, Top, Vector[CurrentID].Value, CurrentID);
				return;
			}
		}
	}
	//Iterative_DFS
	void Print_Number_Edges(std::ofstream& output, std::vector<Node_Main>& Vector, const int& Top) {
		//Declaring_Start_Variables
		int Size = Vector.size();
		std::vector<Node> queue;
		queue.reserve(Size);
		int Trees = 0, Value, ID;
		//Setting_Array_For_Visited_Nodes
		bool* arrBool = new bool[Size];
		for (int b = 0; b < Size; b++) {
			arrBool[b] = false;
		}
		//Starting_Count
		for (int i = 0; i < Size; i++) {
			if (arrBool[i]) continue;
			else {
				//Setting_Value_To_Visited_Also_Add_Its_Neighbours_To_Queue
				arrBool[i] = true;
				queue.insert(queue.end(), Vector[i].Edges.begin(), Vector[i].Edges.end());
				//Working_With_Queue
				while (!queue.empty()) {
					Value = queue.back().Value;
					ID = Search(Vector, Top, Value);
					if (arrBool[ID]) queue.pop_back();
					else {
						//If_It_Is_Not_Visited_Add_Its_Neighbours_To_Queue_And_Continue
						arrBool[ID] = true;
						queue.pop_back();
						queue.insert(queue.end(), Vector[ID].Edges.begin(), Vector[ID].Edges.end());
					}
				}
			}
			//We_Finished_One_Tree_Go_To_Next(If_There_Is_Any)
			Trees += 1;
		}
		output << Trees << std::endl;
	}

	//Recursive_DFS(Creates_Function_Call_Stack_Overflow_With_>1000000_Nodes)
	/*
	//Iterator
	void Iterator(bool* arrBool, const std::vector<Node_Main>& Vector, int startID, const int& Top) {
		for (int i = 0; i < Vector[startID].Edges.size(); i++) {
			int ID = Search(Vector, Top, Vector[startID].Edges[i].Value);
			if (!arrBool[ID]) {
				arrBool[ID] = true;
				Iterator(arrBool, Vector, ID, Top);
			}
		}
	}
	//Main
	void Print_Number_Edges(std::ofstream& output, std::vector<Node_Main>& Vector, const int& Top) {
		//Setting_Start_alues
		int Size = Vector.size();
		bool* arrBool = new bool[Size];
		int Trees = 0;
		for (int i = 0; i < Size; i++) arrBool[i] = false;
		//Starting_Search
		for (int j = 0; j < Size; j++) {
			//If_We_Counted_It
			if (arrBool[j]) continue;
			else arrBool[j] = true;
			Trees += 1;
			Iterator(arrBool, Vector, j, Top);
		}
		output << Trees << std::endl;
	}
	*/
};


//HashTable_Logic
namespace Hash
{
	//Hash_Class_For_Main_HashTable
	class Hash_Main
	{
	public:
		int Value;
		int Size = 8;
		int Active = 0;
		int* Edges = new int[Size];
		Hash_Main(int Value = -1)
			: Value(Value)
		{
			//Set_Array_To_UnInit
			for (int i = 0; i < Size; i++) {
				Edges[i] = -1;
			}
		}
		//Return_Number_Of_Neighbours
		/*
		void Print_Number_Edges(std::ofstream& output) const {
			output << Active << std::endl;
		}
		*/
		//Prints_Neighbours
		void Print_Edges(std::ofstream& output) const {
			//Creating_New_Array_For_Sorting_Without_Tombs_And_UnInit_Values
			int* Arr = new int[Active];
			int j = 0;
			int i = 0;
			for (i = 0; i < Size; i++) {
				if (Edges[i] != -1 && Edges[i] != -2){
					Arr[j] = Edges[i];
					j++;
				}
			}
			//Sorting
			quickSort(Arr, 0, j-1);
			//Printing
			for (i = 0; i < j; i++) {
				output << Arr[i] << " ";
			}
			delete[] Arr;
			output << std::endl;
		}
		//ReSize_Logic_Edges_Array
		void ReSize() {
			//Setting_Starter_Parameters
			int SizeNew = Size * 2;
			int X;
			int* VertNew = new int[SizeNew];
			//Setting_Starting_Values
			for (int j = 0; j < SizeNew; j++) {
				VertNew[j] = -1;
			}
			//Modified_Search
			for (int i = 0; i < Size; i++) {
				if (Edges[i] > -1) {
					//New_Hash_Function
					int Key = mod(Edges[i] * (Edges[i] + 3), SizeNew);
					X = 1;
					//Value=-1->UnInit_New_Array_Cant_Have_Tombs
					while (VertNew[Key] > -1) {
						//Offset_Function:(X^2)/2
						Key = mod(Key + (X ^ 2) / 2, SizeNew);
						X += 1;
					}
					//Setting_New_Value
					VertNew[Key] = Edges[i];
				}
			}
			//Updating_Values
			delete[] Edges;
			Edges = VertNew;
			Size = SizeNew;
		}
		//Insert_To_Edges_Array
		void Insert(const int& Value) {
			//Checking_For_Size_Balance_Before_Inserting
			float ReSizePar = 0.5f;
			if ((float)Active / (float)Size > ReSizePar) ReSize();
			//Hash_Function
			int Key = mod(Value * (Value + 3), Size);
			int X = 0;
			//Value=-1->UnInit_Value=-2->Tomb
			while (Edges[Key] != -1) {
				//If_We_Already_Got_It
				if (Edges[Key] == Value) return;
				//Offset_Function:(X^2)/2
				Key = mod(Key + (X ^ 2) / 2, Size);
				X += 1;
			}
			Edges[Key] = Value;
			Active += 1;
		}
		//Searching_In_Edges_Array
		int Search(const int& Value) {
			//Hash_Function
			int Key = mod(Value * (Value + 3), Size);
			int X = 0;
			//Value=-1->UnInit
			while (Edges[Key] != -1) {
				//If_We_Found_It
				if (Edges[Key] == Value) return Key;
				//Offset_Function:(X^2)/2
				Key = mod(Key + (X ^ 2) / 2, Size);
				X += 1;
			}
			return -1;
		}
		//Delete(Only_In_Sub_Array_Is_Needed)
		void Delete(const int& Value) {
			int Key = Search(Value);
			if (Key != -1) {
				Edges[Key] = -2;
			}
		}
	};

	//Commands_For_Main_Array
	void ReSize(Hash_Main*& Vert, int& Size) {
		//Setting_Starter_Parameters
		int SizeNew = Size * 2;
		int X;
		Hash_Main* VertNew = new Hash_Main[SizeNew];
		//Modified_Search
		for (int i = 0; i < Size; i++) {
			if (Vert[i].Value > -1) {
				//New_Hash_Function
				int Key = mod(Vert[i].Value * (Vert[i].Value + 3), SizeNew);
				X = 1;
				//Value=-1->UnInit_New_Array_Cant_Have_Tombs
				while (VertNew[Key].Value > -1) {
					//Offset_Function:(X^2)/2
					Key = mod(Key + (X ^ 2) / 2, SizeNew);
					X += 1;
				}
				//Setting_New_Value
				VertNew[Key] = Vert[i];
			}
		}
		//Updating_Values
		delete[] Vert;
		Vert = VertNew;
		Size = SizeNew;
	}
	int Insert(Hash_Main*& Vert, int& Size, int& Active, const int& Value) {
		//Hash_Function
		int Key = mod(Value * (Value + 3), Size);
		int X = 1;
		//Value=-1->UnInit_Value=-2->Tomb
		while (Vert[Key].Value != -1) {
			//If_We_Already_Got_It
			if (Vert[Key].Value == Value) return Key;
			//Offset_Function:(X^2)/2
			Key = mod(Key + (X ^ 2) / 2, Size);
			X += 1;
		}
		//Inserting_At_Right_Index
		Vert[Key] = Hash_Main(Value);
		Active += 1;
		return Key;
	}
	int Search(Hash_Main*& Vert, const int& Size, const int& Value) {
		//Hash_Function
		int Key = mod(Value * (Value + 3), Size);
		int X = 0;
		//Value=-1->UnInit
		while (Vert[Key].Value != -1) {
			//If_We_Found_It
			if (Vert[Key].Value == Value) return Key;
			//Offset_Function:(X^2)/2
			Key = mod(Key + (X ^ 2) / 2, Size);
			X += 1;
		}
		return -1;
	}
	//Iterative_DFS(Only_Change_Is_We_Also_Check_For_Values_Validity(UnInit=-1_Tombs=-2)
	void Print_Number_Edges(std::ofstream& output, Hash_Main*& Vert, const int& Size) {
		//Declaring_Start_Variables
		std::vector<int> queue;
		queue.reserve(Size);
		int Trees = 0, Value, ID;
		//Setting_Array_For_Visited_Nodes
		bool* arrBool = new bool[Size];
		for (int b = 0; b < Size; b++) {
			arrBool[b] = false;
		}
		//Starting_Count
		for (int i = 0; i < Size; i++) {
			if (Vert[i].Value < 0) continue;
			if (arrBool[i]) continue;
			else {
				//Set_Value_To_Visited_And_Add_Neghbours_To_Queue
				arrBool[i] = true;
				queue.insert(queue.end(), Vert[i].Edges, Vert[i].Edges + Vert[i].Size);
				//Working_With_Queue
				while (!queue.empty()) {
					//If_Not_Valid_And_Visited_Continue
					Value = queue.back();
					if (Value < 0) {
						queue.pop_back();
					}
					else {
						ID = Search(Vert, Size, Value);
						if (arrBool[ID]) queue.pop_back();
						else {
							//Set_Value_To_Visited_And_Add_Neghbours_To_Queue
							arrBool[ID] = true;
							queue.pop_back();
							queue.insert(queue.end(), Vert[ID].Edges, Vert[ID].Edges + Vert[ID].Size);
						}
					}
				}
			}
			//We_Have_Visited_All_Nodes_In_Current_Tree
			Trees += 1;
		}
		output << Trees << std::endl;
	}

	//Recursive_DFS(Produces_Function_Call_Stack_Overflow_With_>1000000_Nodes)
	/*
	//Iterator
	void Iterator(bool* arrBool, Hash_Main*& Vert, int startID, const int& Size) {
		for (int i = 0; i < Vert[startID].Size; i++) {
			if (Vert[startID].Edges[i] < 0) continue;
			int ID = Search(Vert, Size, Vert[startID].Edges[i]);
			if (!arrBool[ID]) {
				arrBool[ID] = true;
				Iterator(arrBool, Vert, ID, Size);
			}
		}
	}
	//Main
	void Print_Number_Edges(std::ofstream& output, Hash_Main*& Vert, const int& Size) {
		//Setting_Start_alues
		bool* arrBool = new bool[Size];
		int Trees = 0;
		for (int i = 0; i < Size; i++) arrBool[i] = false;
		//Starting_Search
		for (int j = 0; j < Size; j++) {
			//If_Its_Tomb_Or_Empty
			if (Vert[j].Value < 0) continue;
			//If_We_Counted_It
			if (arrBool[j]) continue;
			else arrBool[j] = true;
			Trees += 1;
			Iterator(arrBool, Vert, j, Size);
		}
		output << Trees << std::endl;
	}
	*/
};


int main(int argc, char* argv[])
{
	//We_Know_That_We_Pass_Only_One_Argument
	int execParam = atoi(argv[1]);
	//int execParam = 3;
	//Opening_Main_File
	std::ifstream fileCommands("commands.txt");
	std::ofstream outFile("output.txt");
	//Checking_If_File_Has_Opened
	if (!fileCommands.is_open()) {
		outFile << "File can't be opened";
		return -1;
	}
	std::string bufferCommand;
	std::string Command;
	int A, B;
	//Selecting_Commands
	if (execParam == 1) {
		using namespace Array;
		//Declaring_Basic_Variables_For_Stream
		int objA_ID, objB_ID;
		std::vector<myArr> MainArr;
		//We_Need_To_Parse_Each_Line_With_Unique_Way_Because_Input_Isn't_Unified
		while (std::getline(fileCommands, bufferCommand)) {
			//Getting_Commands
			Command = bufferCommand.substr(0, bufferCommand.find(" "));
			if (Command == "READ_DATA") {
				//Timer XYZ;
				//Setting_Stream
				std::ifstream startEdges("input.txt");
				if (!startEdges.is_open()) {
					outFile << "File can't be opened";
					return -1;
				}
				//Input_Is_Unified_We_Can_Just_Stream_It
				while (startEdges >> A >> B) {
					//Insertion_For_A
					objA_ID = Insert(MainArr, A);
					MainArr[objA_ID].Insert(B);
					//std::thread T1(&myArr::Insert, MainArr[objA_ID], B);
					//Insertion_For_B
					objB_ID = Insert(MainArr, B);
					MainArr[objB_ID].Insert(A);
					//std::thread T2(&myArr::Insert, MainArr[objB_ID], A);
					//T1.join();
					//T2.join();
				}
				continue;
			}
			if (Command == "INSERT_LINK") {
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Insertion_For_A
				objA_ID = Insert(MainArr, A);
				MainArr[objA_ID].Insert(B);
				//std::thread T1(&myArr::Insert, MainArr[objA_ID], B);
				//Insertion_For_B
				objB_ID = Insert(MainArr, B);
				MainArr[objB_ID].Insert(A);
				//std::thread T2(&myArr::Insert, MainArr[objB_ID], A);
				//T1.join();
				//T2.join();
				continue;
			}
			if (Command == "DELETE_LINK") {
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Insertion_For_A
				objA_ID = Search(MainArr, A);
				if (objA_ID != -1) MainArr[objA_ID].Delete(B);
				//Insertion_For_B
				objB_ID = Search(MainArr, B);
				if (objB_ID != -1) MainArr[objB_ID].Delete(A);
				continue;
			}
			if (Command == "FIND_NEIGHBORS") {
				//Reading_Vertex
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				//Finding_A_And_Printing_Its_Connections
				objA_ID = Search(MainArr, A);
				if (objA_ID != -1) MainArr[objA_ID].Print_Edges(outFile);
				continue;
			}
			if (Command == "FIND_NUM_CONNECTED_COMPONENTS") {
				Print_Number_Edges(outFile, MainArr);
				continue;
			}
		}
	}
	if (execParam == 2) {
		using namespace Tree;
		//Declaring_Basic_Parameters_For_AVL_Tree
		std::vector<Node_Main> MainArr;
		int MainEdgesTopID = -1;
		//Declaring_Start_Values_For_Input
		int objA_ID, objB_ID;
		//We_Need_To_Parse_Each_Line_With_Unique_Way_Because_Input_Isn't_Unified
		while (std::getline(fileCommands, bufferCommand)) {
			//Getting_Commands
			Command = bufferCommand.substr(0, bufferCommand.find(' '));
			if (Command == "READ_DATA") {
				//Timer XYZ;
				//Setting_Stream
				std::ifstream startEdges("input.txt");
				if (!startEdges.is_open()) {
					outFile << "File can't be opened";
					return -1;
				}
				//Input_Is_Unified_We_Can_Just_Stream_It
				while (startEdges >> A >> B) {
					//Insertion_For_A
					objA_ID = Insert(MainArr, MainEdgesTopID, A);
					Insert(MainArr[objA_ID].Edges, MainArr[objA_ID].EdgesTopID, B);
					//std::thread T1(Insert<Node>, MainArr[objA_ID].Edges, MainArr[objA_ID].EdgesTopID, B);
					//Insertion_For_B
					objB_ID = Insert(MainArr, MainEdgesTopID, B);
					Insert(MainArr[objB_ID].Edges, MainArr[objB_ID].EdgesTopID, A);
					//std::thread T2(Insert<Node>, MainArr[objB_ID].Edges, MainArr[objB_ID].EdgesTopID, A);
					//T1.join();
					//T2.join();
				}
				continue;
			}
			if (Command == "INSERT_LINK") {
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Insertion_For_A
				objA_ID = Insert(MainArr, MainEdgesTopID, A);
				Insert(MainArr[objA_ID].Edges, MainArr[objA_ID].EdgesTopID, B);
				//std::thread T1(Insert<Node>, MainArr[objA_ID].Edges, MainArr[objA_ID].EdgesTopID, B);
				//Insertion_For_B
				objB_ID = Insert(MainArr, MainEdgesTopID, B);
				Insert(MainArr[objB_ID].Edges, MainArr[objB_ID].EdgesTopID, A);
				//std::thread T2(Insert<Node>, MainArr[objB_ID].Edges, MainArr[objB_ID].EdgesTopID, A);
				//T1.join();
				//T2.join();
				continue;
			}
			if (Command == "DELETE_LINK") {
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Deletion_For_A
				objA_ID = Search(MainArr, MainEdgesTopID, A);
				if (objA_ID != -1) Delete(MainArr[objA_ID].Edges, MainArr[objA_ID].EdgesTopID, B);
				//Deletion_For_B
				objB_ID = Search(MainArr, MainEdgesTopID, B);
				if (objB_ID != -1) Delete(MainArr[objB_ID].Edges, MainArr[objB_ID].EdgesTopID, A);
				continue;
			}
			if (Command == "FIND_NEIGHBORS") {
				//Reading_Vertex
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				//Finding_A_And_Printing_Its_Connections
				objA_ID = Search(MainArr, MainEdgesTopID, A);
				if (objA_ID != -1){
				MainArr[objA_ID].Print_Edges(outFile, MainArr[objA_ID].EdgesTopID);
				outFile << std::endl;
				}
				continue;
			}
			if (Command == "FIND_NUM_CONNECTED_COMPONENTS") {
				Print_Number_Edges(outFile, MainArr, MainEdgesTopID);
				continue;
			}
		}
	}
	if (execParam == 3) {
		using namespace Hash;
		//Declaring_Basic_Parameters_For_Hash_Table
		int Size = 64;
		int Active = 0;
		Hash_Main* MainArr = new Hash_Main[Size];
		//Variables_For_Input
		int objA_ID, objB_ID;
		float ReSizePar = 0.5f;
		//We_Need_To_Parse_Each_Line_With_Unique_Way_Because_Input_Isn't_Unified
		while (std::getline(fileCommands, bufferCommand)) {
			//Getting_Commands
			Command = bufferCommand.substr(0, bufferCommand.find(' '));
			if (Command == "READ_DATA") {
				//Timer XYZ;
				//Setting_Stream
				std::ifstream startEdges("input.txt");
				if (!startEdges.is_open()) {
					outFile << "File can't be opened";
					return -1;
				}
				//Input_Is_Unified_We_Can_Just_Stream_It
				while (startEdges >> A >> B) {
					//Checking_For_Resizing_Otherwise_We_Can_Get_Invalid_IDs
					if ((float)Active / (float)Size > ReSizePar) ReSize(MainArr, Size);
					//Insertion_For_A
					objA_ID = Insert(MainArr, Size, Active, A);
					MainArr[objA_ID].Insert(B);
					//std::thread T1(&Hash_Main::Insert, MainArr[objA_ID], B);
					//Insertion_For_B
					objB_ID = Insert(MainArr, Size, Active, B);
					MainArr[objB_ID].Insert(A);
					//std::thread T2(&Hash_Main::Insert, MainArr[objB_ID], A);
					//T1.join();
					//T2.join();
				}
				continue;
			}
			if (Command == "INSERT_LINK") {
				//Checking_For_Resizing_Otherwise_We_Can_Get_Invalid_IDs
				if ((float)Active / (float)Size > ReSizePar) ReSize(MainArr, Size);
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Insertion_For_A
				objA_ID = Insert(MainArr, Size, Active, A);
				MainArr[objA_ID].Insert(B);
				//std::thread T1(&Hash_Main::Insert, MainArr[objA_ID], B);
				//Insertion_For_B
				objB_ID = Insert(MainArr, Size, Active, B);
				MainArr[objB_ID].Insert(A);
				//std::thread T2(&Hash_Main::Insert, MainArr[objB_ID], A);
				//T1.join();
				//T2.join();
				continue;
			}
			if (Command == "DELETE_LINK") {
				//Reading_Vertexes
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				B = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 3, bufferCommand.find(' ') + 4));
				//Searching_Main_Vertex_Edges
				objA_ID = Search(MainArr, Size, A);
				objB_ID = Search(MainArr, Size, B);
				//If_Found_Perform_Deletion(Use_OR_Because_There_Is_Always_Possibility_Of_Bug_When_B_Has_Edge_But_A_Doesnt)
				if (objA_ID != -1) MainArr[objA_ID].Delete(B);
				if (objB_ID != -1) MainArr[objB_ID].Delete(A);
				continue;
			}
			if (Command == "FIND_NEIGHBORS") {
				//Reading_Vertex
				A = std::stoi(bufferCommand.substr(bufferCommand.find(' ') + 1, bufferCommand.find(' ') + 2));
				//Finding_A_And_Printing_Its_Connections
				objA_ID = Search(MainArr, Size, A);
				if (objA_ID != -1) MainArr[objA_ID].Print_Edges(outFile);
				continue;
			}
			if (Command == "FIND_NUM_CONNECTED_COMPONENTS") {
				Print_Number_Edges(outFile, MainArr, Size);
				continue;
			}
		}
	}
}