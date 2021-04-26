<style>
	h1	{color:#CC8CE9;}
	h2	{color:#C619D3;}
	h3	{color:#D31983;}
	h4	{color:#D31983;}
	body	
	{
		background-image: url("https://cdn.discordapp.com/attachments/588054501303255273/814543243260854312/cancer.jpg");
		background-size: 100% auto;
		background-repeat: repeat-y;
		background-color: #111F59;
	}
	div
	{
		padding: 10px;
		background-color: rgba(15, 0, 50, 0.50);
	}
	li	{color: rgba(240, 213, 173, 1)}
	hr
	{
		height:2px;
		border-width:0;
		color:gray;
		background-color:gray
	}
	p	{color: rgba(225, 227, 234, 1)}
</style>

# Assignment

After getting her PhD, Christie has become a celebrity at her university,
  and her facebook profile is full of friend requests. Being the nice girl she is,
  Christie has accepted all the requests.

Now Kuldeep is jealous of all the attention she is getting from other guys,
  so he asks her to delete some of the guys from her friend list.

To avoid a 'scene', Christie decides to remove some friends from her friend list,
  since she knows the popularity of each of the friend she has, she uses the following algorithm to delete a friend.

```c++
Algorithm Delete(Friend):
    DeleteFriend=false
    for i = 1 to Friend.length-1
         if (Friend[i].popularity < Friend[i+1].popularity)
            delete i th friend
            DeleteFriend=true
            break
    if(DeleteFriend == false)
        delete the last friend
```

Input:
First line contains T number of test cases. First line of each test case contains N,
  the number of friends Christie currently has and K ,the number of friends Christie decides to delete.
  Next lines contains popularity of her friends separated by space.

Output:
For each test case print N-K numbers which represent popularity of Christie friend's after deleting K friends.

Constraints
1<=T<=1000
1<=N<=100000
0<=K< N
0<=popularity_of_friend<=100

NOTE:
Order of friends after deleting exactly K friends should be maintained as given in input.

---

# Dev Notes

### Lets name the function <i>"BridgeBurner"</i>

The function should remove the friend with the lowest popularity score.
If such a friend is not found - remove the last one in the array

Note: Implement 2 ways of solving the issue

-	With Vectors/Arrays
-	With Linked list

Both solutions will make use of the Friend Class from FriendClass.h/.cpp

```c++
class Friend
{
public:
	Friend();
	Friend(int newPopularity);
	Friend(std::string newName, int newPopularity);

private:
	std::string name;
	        int popularity;

public:
	std::string getName();
	       void setName(std::string newName = "");

	        int getPopularity();
	       void setPopularity(int newPopularity = 0);


	       bool isMorePopular(class Friend rival);
	       bool isLessPopular(class Friend rival);

	       void display(bool newLine = false);
};
```

Algorithm ignores the lowest value and looks only for a relative min.

If the list is sorted, then the alorithm would remove the absolute min.

However this is not mentioned in the assignment.

The vector solution was made to ease development