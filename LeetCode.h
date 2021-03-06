#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

//直线方程：Ax + By + C = 0
struct Line {
	int A;
	int B;
	int C;
	Line() : A(0), B(0), C(0) {}
	Line(int a, int b, int c) : A(a), B(b), C(c) {}
	bool operator==(const Line &l) const {					//重载==运算符
		return A == l.A && B == l.B && C == l.C;
	}
};

//快速排序
void quickSort(int a[], int n);
void quickSort2(int A[], int start, int end);

//链表逆置
ListNode* ReverseLinkList(ListNode* head);

//二分搜索
int BinarySearch(int a[], int n, int target);
int BinarySearchLeft(int a[], int n, int target);					//如果有重复的数，返回第一个
int BinarySearchRight(int a[], int n, int target);					//如果有重复的数，返回最后一个

//归并排序
void MergeSort(int a[], int start, int end);						//递归版本
void MergeSort2(int a[], int n);									//迭代版本
void Merge(int a[], int start1, int end1, int start2, int end2);

//最小堆
void createHeap(int A[], int n);			//建堆
void adjustDown(int A[], int r, int last);	//r + 1到last都满足堆的要求，将r位置上的元素也调整满足堆的要求
void adjustUp(int A[], int last);			//last之前的元素都满足堆的要求，将last位置上的元素调整满足堆的要求
void heapSort(int A[], int n);				//堆排序，因为是最小堆，所以是降序

//程序员面试金典 p.54 4.4 创建某一深度上所有结点的链表
ListNode* BuildListFromBTree(TreeNode* root, int n);				//n代表想建立链表的二叉树某一层的深度

// 打印和的拆解
void printSum(int n);
void printSum(int n, int m, int s, vector<int> &vec);

// 计算日期
void CalcDate();
int IsRunNian(int year);

// [MSOnlineTest] 1.String reorder
void stringReorder(string s);

// [MSOnlineTest] 2.K-th string
void Kthstring(int n, int m, int k);								//DFS，枚举所有解，找出第k个输出
bool Kthstring(int n, int m, int k, int &num, string &s);
void Kthstring2(int n, int m, int k);								//DP

// [LeetCode] Reverse Integer
int reverse(int x);			//有可能导致溢出

// [LeetCode] Regular Expression Matching
bool isMatch(const char *s, const char *p);							//递归
bool isMatch2(const char *s, const char *p);						//迭代，WA，对a*a这样的情况处理不好

// [LeetCode] Wildcard Matching
bool isMatchII(const char *s, const char *p);						//递归，TLE
bool isMatchP(const char *s, const char *p);

// [LeetCode] Search in Rotated Sorted Array
int search(int A[], int n, int target);
int search2(int A[], int n, int target);

// [LeetCode] Search in Rotated Sorted Array II
bool searchII(int A[], int n, int target);

// [LeetCode] Binary Tree Preorder Traversal
vector<int> preorderTraversal(TreeNode *root);						//递归
void preorderTraversal(TreeNode *root, vector<int> &vec);
vector<int> preorderTraversal2(TreeNode *root);						//迭代

// [LeetCode] Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode *root);						//迭代

// [LeetCode] Binary Tree Postorder Traversal
vector<int> postorderTraversal(TreeNode *root);						//迭代
void visitAndSetCurr(stack<TreeNode *> &stk, TreeNode * &curr, vector<int> &result);

// [LeetCode] Convert Sorted Array to Binary Search Tree
TreeNode *sortedArrayToBST(vector<int> &num);
TreeNode *sortedArrayToBST(vector<int> &num, int start, int end);

// [LeetCode] Convert Sorted List to Binary Search Tree
TreeNode *sortedListToBST(ListNode *head);									//一种自底向上的方法
TreeNode *sortedListToBST(ListNode* &list, int start, int end);				//***
TreeNode *sortedListToBST2(ListNode *head);									//偷懒，将链表转换为数组

// [LeetCode] Binary Tree Level Order Traversal
vector<vector<int> > levelOrder(TreeNode *root);

// [LeetCode] Binary Tree Level Order Traversal II
vector<vector<int> > levelOrderBottom(TreeNode *root);
void levelOrderBottom(queue<TreeNode *> &q, vector<vector<int> > &result);

// [LeetCode] Binary Tree Zigzag Level Order Traversal
vector<vector<int> > zigzagLevelOrder(TreeNode *root);

// [LeetCode] Flatten Binary Tree to Linked List
void flatten(TreeNode* root);
void flattenP(TreeNode* root, TreeNode** last);

// [LeetCode] Construct Binary Tree from Preorder and Inorder Traversal
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTreeP(vector<int>::iterator PreIterStart,
	vector<int>::iterator PreIterEnd,
	vector<int>::iterator InIterStart,
	vector<int>::iterator InIterEnd);

// [LeetCode] Construct Binary Tree from Inorder and Postorder Traversal
TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);
TreeNode *buildTreeP2(vector<int>::iterator InIterStart,
	vector<int>::iterator InIterEnd,
	vector<int>::iterator PostIterStart,
	vector<int>::iterator PostIterEnd);

// [LeetCode] Unique Binary Search Trees
int numTrees(int n);
int CalNum(int n, int num[]);									//递归版本
int numTrees2(int n);											//迭代版本

// [LeetCode] Unique Binary Search Trees II
vector<TreeNode *> generateTrees(int n);
vector<TreeNode *> generateTrees(int start, int end);

// [LeetCode] Path Sum
bool hasPathSum(TreeNode *root, int sum);

// [LeetCode] Path Sum II
vector<vector<int> > pathSum(TreeNode *root, int sum);
void pathSumP(TreeNode *root, int sum, vector<int>& vec, vector<vector<int> >& result);

// [LeetCode] Sum Root to Leaf Numbers
int sumNumbers(TreeNode *root);
void sumNumbersP(TreeNode *root, int& sum, int& totalsum);

// [LeetCode] Search for a Range
vector<int> searchRange(int A[], int n, int target);

// [LeetCode] Subsets
vector<vector<int> > subsets(vector<int> &S);			//方法一
vector<vector<int> > subsets2(vector<int> &S);			//方法二：DFS
void subsets2(vector<int> &S, int step, vector<int> &vec, vector<vector<int> > &result);

// [LeetCode] Subsets II
vector<vector<int> > subsetsWithDup(vector<int> &S);

// [LeetCode] Reorder List
void reorderList(ListNode *head);
ListNode *FindMiddleNode(ListNode *head);
void MergeList(ListNode *head, ListNode *head2);

// [LeetCode] Combinations
vector<vector<int> > combine(int n, int k);
void combine(int start, int end, int k, vector<int> &vec, vector<vector<int> > &result);

// [LeetCode] Permutations
vector<vector<int> > permute(vector<int> &num);
void permute(vector<int> &num, size_t start, vector<int> &vec, vector<vector<int> > &result);

// [LeetCode] Permutations II
vector<vector<int> > permuteUnique(vector<int>& num);
void permuteUnique(vector<int> &num, size_t start, vector<int> &vec, vector<vector<int> > &result);
bool isExist(vector<int> &num, int start, int end, int target);

// [LeetCode] Pascal's Triangle
vector<vector<int> > generate(int numRows);

// [LeetCode] Pascal's Triangle II
vector<int> getRow(int rowIndex);

//[LeetCode] Minimum Path Sum
int minPathSum(vector<vector<int> > &grid);
void showMinPath(vector<vector<int> > &grid, vector<vector<int> > &f);
void printMinPath(vector<vector<int> > &grid, vector<vector<int> > &f, int row, int col);

//[LeetCode] Unique Paths
int uniquePaths(int m, int n);				// DFS
int uniquePaths2(int m, int n);				// DP

//[LeetCode] Unique Paths II
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid);

// [LeetCode] Triangle
int minimumTotal(vector<vector<int> > &triangle);			//DFS，会TLE
void DFS(vector<vector<int> > &triangle, int &MinNum, int row, int col, int num);
int minimumTotal2(vector<vector<int> > &triangle);			//DP

// [LeetCode] Reverse Linked List II
ListNode *reverseBetween(ListNode *head, int m, int n);

// [LeetCode] Symmetric Tree
bool isSymmetric(TreeNode *root);
bool checkSymmetric(TreeNode *left, TreeNode *right);

// [LeetCode] N-Queens
vector<vector<string> > solveNQueens(int n);
void solveNQueens(int n, int level, vector<pair<int, int> > &vec, vector<vector<string> > &result);
void checkF(vector<pair<int, int> > &vec, vector<bool> &f, int level);
void addResult(int n, vector<pair<int, int> > &vec, vector<vector<string> > &result);

// [LeetCode] Restore IP Addresses
vector<string> restoreIpAddresses(string s);
void restoreIpAddresses(string &s, int start, int level, string &str, vector<string> &result);
bool isVaildIp(string &s, int start, int len);

// [LeetCode] Validate Binary Search Tree
bool isValidBST(TreeNode *root);
bool isValidBST(TreeNode *root, int upper, int lower);

// [LeetCode] Combination Sum
vector<vector<int> > combinationSum(vector<int> &candidates, int target);
void combinationSum(vector<int> &candidates, int start, int target, vector<int> &vec, vector<vector<int> > &result);

// [LeetCode] Combination Sum II
vector<vector<int> > combinationSum2(vector<int> &num, int target);
void combinationSum2(vector<int> &num, int start, int target, vector<int> &vec, vector<vector<int> > &result);

// [LeetCode] Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits);
void letterCombinations(string &digits, int start, string &s, vector<string> &tel, vector<string> &result);

// [LeetCode] Generate Parentheses
vector<string> generateParenthesis(int n);
void generateParenthesis(int n, int step, int left, int right, string &s, vector<string> &result);

// [LeetCode] Sudoku Solver
void solveSudoku(vector<vector<char> > &board);
bool solveSudoku(vector<vector<char> > &board, int row, int col);
bool isValidChar(vector<vector<char> > &board, char ch, int row, int col);

// [LeetCode] Word Search
bool exist(vector<vector<char> > &board, string word);
bool exist(vector<vector<char> > &board, int row, int col, string &word, int step, vector<vector<bool> > &isUsed);

// [LeetCode] Recover Binary Search Tree
void recoverTree(TreeNode *root);		//先中序遍历得到有序数组，再从有序数组中找到被交换的两个数交换回来，O(n)空间
void recoverTree(TreeNode *root, vector<TreeNode*> &vec);
void recoverTree2(TreeNode *root);		//边中序遍历边找被交换的两个数，遍历结束后得到要交换的两个节点指针，O(1)空间
void recoverTree2(TreeNode *root, TreeNode **last, TreeNode **p1, TreeNode **p2);

// [LeetCode] Maximum Subarray
int maxSubArray(int A[], int n);								//返回最大连续子数组和
pair<int, int> findMaxSubArray(int A[], int n);					//返回最大连续子数组和的首尾下标

// [LeetCode] Longest Palindromic Substring
string longestPalindrome(string s);
pair<int, int> findLongestPalindrome0(string &str, int start, int end);			//WA
pair<int, int> findLongestPalindrome1(string &str, int start, int end);			//每个元素向两边扫描，时间复杂度O(n^2)，空间复杂度O(1)
pair<int, int> findLongestPalindrome2(string &str, int start, int end, vector<vector<pair<int, int> > > &f);			//递归 + 备忘录，TLE
pair<int, int> findLongestPalindrome3(string &str, int start, int end);			//DP，时间复杂度O(n^2)，空间复杂度O(n^2)，TLE
pair<int, int> findLongestPalindrome4(string &str, int start, int end);			//Manacher’s algorithm，时间复杂度O(n)，空间复杂度O(n)

// [LeetCode] Palindrome Partitioning
vector<vector<string> > partition(string s);
void partition(string &s, int start, int end, vector<string> &vec, vector<vector<string> > &result);
bool isPalindrome(const string &s, int start, int end);

// [LeetCode] Palindrome Partitioning II													//***
int minCut(string s);																		//DP
int minCut(string &s, int start, int end);													//WA
void minCut(string &s, int start, int cut, int &min);										//DFS，与Palindrome Partitioning类似，只需存储Cut个数，会TLE

// [LeetCode] Interleaving String
bool isInterleave(string s1, string s2, string s3);
bool isInterleave(string &s1, int p1, string &s2, int p2, string &s3, int p3);		//DFS，会TLE
bool isInterleave2(string s1, string s2, string s3);								//DP

// [LeetCode] Candy
int candy(vector<int> &ratings);	//找“^”型
int candy2(vector<int> &ratings);	//更简洁的写法，两遍扫描

// [LeetCode] Trapping Rain Water	//******
int trap(int A[], int n);			//WA，算法有问题
int trap2(int A[], int n);			//横向扫描，会TLE
int trap3(int A[], int n);			//计算每个位置能容纳的水，O(n)空间
int trap4(int A[], int n);			//找到最高的位置，然后分别计算两边每个位置能容纳的水，O(1)空间
int trap5(int A[], int n);			//维护一个单调栈

// [LeetCode] Decode Ways
int numDecodings(const string &s);
void numDecodings(const string &s, int start, int &total);		//DFS，会TLE
int numDecodings2(const string &s);								//DP

// [LeetCode] Distinct Subsequences
int numDistinct(string S, string T);
void numDistinct(string &S, int startS, string &T, int startT, int &total);		//DFS，会TLE
int numDistinct2(string S, string T);											//二维DP
int numDistinct3(string S, string T);											//DP + 滚动数组

// [LeetCode] Add Two Numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

// [LeetCode] Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s);					// O(n^2)，可以过，但有更好的O(n)解法

// [LeetCode] Next Permutation
void nextPermutation(vector<int> &num);

// [LeetCode] Permutation Sequence
string getPermutation(int n, int k);

// [LeetCode] Gray Code 
vector<int> grayCode(int n);

// [LeetCode] Plus One
vector<int> plusOne(vector<int> &digits);

// [LeetCode] Climbing Stairs
int climbStairs(int n);

// [LeetCode] Longest Consecutive Sequence
int longestConsecutive(vector<int> &num);

// [LeetCode] Two Sum
vector<int> twoSum(vector<int> &numbers, int target);			// O(n^2)，会TLE
vector<int> twoSum2(vector<int> &numbers, int target);			// hash， O(n)

// [LeetCode] 3Sum
vector<vector<int> > threeSum(vector<int> &num);

// [LeetCode] 3Sum Closest
int threeSumClosest(vector<int> &num, int target);

// [LeetCode] 4Sum
vector<vector<int> > fourSum(vector<int> &num, int target);		//时间复杂度O(n^3)，TLE

// [LeetCode] Length of Last Word
int lengthOfLastWord(const char *s);

// [LeetCode] Divide Two Integers
int divide(int dividend, int divisor);			//TLE

// [LeetCode] Remove Nth Node From End of List
ListNode *removeNthFromEnd(ListNode *head, int n);

// [LeetCode] ZigZag Conversion
string convert(string s, int nRows);

// [LeetCode] Valid Palindrome
bool isPalindrome(string s);
bool isAlphanumeric(char &ch);			//判断是否是字母和数字，如果是大写字母则转换成小写字母

// [LeetCode] Count and Say
string countAndSay(int n);
void convertIntToStr(int n, string &result);		//将整数n转换成字符串并插入到result后面

// [LeetCode] Valid Parentheses
bool isValid(string s);

// [LeetCode] Longest Valid Parentheses			//***
int longestValidParentheses(string s);			//借助栈，也可以用DP

// [LeetCode] Rotate List
ListNode *rotateRight(ListNode *head, int k);

// [LeetCode] Merge Intervals
vector<Interval> merge(vector<Interval> &intervals);						//多次CE，sort函数、函数对象的使用
bool IntervalCompare(const Interval &v1, const Interval &v2);

// [LeetCode] Insert Interval
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);

// [LeetCode] Balanced Binary Tree
bool isBalanced(TreeNode *root);
bool isBalanced(TreeNode *root, int &height);

// [LeetCode] Max Points on a Line							//测试用例有点变态 →_→
struct line_hash {											//自定义Line的hash函数  
	size_t operator()(const Line &l) const {
		return (l.A << 10) + (l.B << 5) + l.C;
	}
};
int gcd(int a, int b);									   //求a和b的最大公约数，假设a和b均为非负
int maxPoints(vector<Point> &points);

// [LeetCode] Minimum Window Substring					   //***
string minWindow(string S, string T);

// [LeetCode] Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices);

// [LeetCode] Best Time to Buy and Sell Stock II
int maxProfit2(vector<int> &prices);

// [LeetCode] Best Time to Buy and Sell Stock III
int maxProfit3(vector<int> &prices);
//在范围内求一次交易最大利润，代码与maxProfit类似。返回值是最大利润，p是买进卖出点的下标，bReverse是倒过来求（找最大赔钱数）
int maxProfit(vector<int> &prices, int start, int end, pair<int, int> *p, bool bReverse);

// [LeetCode] Simplify Path
string simplifyPath(string path);

// [LeetCode] Gas Station
int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

// [LeetCode] Substring with Concatenation of All Words
vector<int> findSubstring(string S, vector<string> &L);			//WA，O(n)，算法本身有问题，代码里有用例
vector<int> findSubstring2(string S, vector<string> &L);		//O(m*n)

// [LeetCode] Spiral Matrix
vector<int> spiralOrder(vector<vector<int> > &matrix);

// [LeetCode] Spiral Matrix II
vector<vector<int> > generateMatrix(int n);

// [LeetCode] Set Matrix Zeroes
void setZeroes(vector<vector<int> > &matrix);

// [LeetCode] Rotate Image
void rotate(vector<vector<int> > &matrix);

// [LeetCode] Largest Rectangle in Histogram			//******
int largestRectangleArea(vector<int> &height);			//单调队列的应用
int largestRectangleArea2(vector<int> &height);

// [LeetCode] Maximal Rectangle
int maximalRectangle(vector<vector<char> > &matrix);	//利用“求直方图中最大矩形”的思想
int maximalRectangle2(vector<vector<char> > &matrix);

// [LeetCode] Valid Sudoku
bool isValidSudoku(vector<vector<char> > &board);

// [LeetCode] Roman to Integer
int romanToInt(string s);

// [LeetCode] Integer to Roman
string intToRoman(int num);

// [LeetCode] Jump Game
bool canJump(int A[], int n);
bool canJump(int A[], int start, int n, vector<bool>& vec);		//深搜 + 备忘录，TLE
bool canJump2(int A[], int n);

// [LeetCode] Jump Game II
int jump(int A[], int n);			//需要O(n)空间
int jump2(int A[], int n);			//O(1)空间

// [LeetCode] Word Break
bool wordBreak(string s, unordered_set<string> &dict);
bool wordBreak(string &s, size_t start, unordered_set<string> &dict);	//深搜，TLE，时间复杂度O(2^n) <--如何计算？
bool wordBreak2(string s, unordered_set<string> &dict);					//DP，时间复杂度O(n^2)

// [LeetCode] Word Break II
vector<string> wordBreakII(string s, unordered_set<string> &dict);		//DP + DFS
void wordBreakII(string &s, int cur, unordered_set<string> &dict, vector<bool> &f, vector<string> &path, vector<string> &result);

// [LeetCode] Edit Distance
int minDistance(string word1, string word2);
void minDistance(string &word1, string &word2, int p1, int p2, int distance, int &minD);	//深搜，TLE
int minDistance2(string word1, string word2);												//DP
int minDistance3(string word1, string word2);												//DP（滚动数组）

// [LeetCode] Single Number
int singleNumber(int A[], int n);		//使用哈希表，O(n)空间
int singleNumber2(int A[], int n);		//借助异或性质，O(1)空间

// [LeetCode] Single Number II
int singleNumberII(int A[], int n);		//位运算

// [LeetCode] Copy List with Random Pointer
RandomListNode *copyRandomList(RandomListNode *head);		//建立新旧节点的映射，需要O(n)空间
RandomListNode *copyRandomList2(RandomListNode *head);		//三次扫描，O(1)空间

// [LeetCode] Partition List
ListNode *partition(ListNode *head, int x);

// [LeetCode] Implement strStr()
char *strStr(char *haystack, char *needle);			//暴力匹配，O(m * n)
char *strStr2(char *haystack, char *needle);		//KMP

// [LeetCode] Sqrt(x)	//***
int sqrt(int x);		//二分，特别注意边界情况

// [LeetCode] Evaluate Reverse Polish Notation
int evalRPN(vector<string> &tokens);
int isOperator(const string& s);
int stringToInt(const string& s);

// [LeetCode] String to Integer(atoi)
int my_atoi(const char *str);			//注意溢出的判断

// [LeetCode] Reverse Words in a String
void reverseWords(string &s);			//O(n)空间
void reverseWords2(string &s);			//O(1)空间
void reversePart(string &s, int start, int end);

// [LeetCode] Sort List
ListNode *sortList(ListNode *head);
ListNode *quickSortList(ListNode *head, ListNode * &tail);		//快速排序，TLE

// [LeetCode] First Missing Positive
int firstMissingPositive(int A[], int n);

// [LeetCode] Median of Two Sorted Arrays				//***，很tricky
double findMedianSortedArrays(int A[], int m, int B[], int n);
int findKthNumber(int A[], int m, int B[], int n, int k);
double findMedianSortedArrays2(int A[], int m, int B[], int n);

// [LeetCode] LRU Cache
class LRUCache{
private:
	size_t maxSize;
	list<pair<int, int> > lst;									// <key, value>
	unordered_map<int, list<pair<int, int> >::iterator> um;		// <key, 链表节点指针>

public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value);
};

// [LeetCode] Binary Tree Maximum Path Sum
int maxPathSum(TreeNode *root);
int maxPathSum(TreeNode *root, int &singlePath);

// [LeetCode] Palindrome Number
bool isPalindrome(int x);					//逆置后比较是否相等，注意防止溢出
bool isPalindrome2(int x);					//每次比较最高和最低位是否相等

// [LeetCode] Maximum Product Subarray
int maxProduct(int A[], int n);

// [LeetCode] Linked List Cycle
bool hasCycle(ListNode *head);

// [LeetCode] Linked List Cycle II
ListNode *detectCycle(ListNode *head);

// [LeetCode] Find Minimum in Rotated Sorted Array
int findMin(vector<int> &num);

// [LeetCode] Find Minimum in Rotated Sorted Array II
int findMin2(vector<int> &num);

// [LeetCode] Container With Most Water
int maxArea(vector<int> &height);

// [LeetCode] Longest Common Prefix
string longestCommonPrefix(vector<string> &strs);

// [LeetCode] Missing Number 
int missingNumber(vector<int>& nums);

// [LeetCode] Binary Tree Paths
vector<string> binaryTreePaths(TreeNode* root);
void binaryTreePaths(TreeNode* root, vector<int>& path, vector<string>& result);
void printPaths(vector<int>& path, vector<string>& result);

// [LeetCode] House Robber
int rob(vector<int>& nums);

// [LeetCode] House Robber II
int robII(vector<int>& nums);

// [LeetCode] Lowest Common Ancestor of a Binary Search Tree
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);
bool isBetween(int center, int left, int right);

// [LeetCode] Lowest Common Ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);	//1000+ms
void findNodes(TreeNode* root, TreeNode* p, TreeNode* q, bool& findP, bool& findQ);
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);	//20+ms
void traversal(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& vec, vector<TreeNode*>& rootToP, vector<TreeNode*>& rootToQ);