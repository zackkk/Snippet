/*
	Facebook Interview Question
	给你一个set<object> 然后给你了个compareTo的方法，可以比较出大小
	任意两个objects都能比较出大小，但是这种关系不具有传递性，即A>B,B>C但是A不一定大于C),
	让你找出set中最大的object，如果不存在，就返回null。

	第七题的解法，可以联想到擂台赛的解法，就是扫两次，第一扫的时候，找到其中最大的object，
	第二次扫的时候，让A可所以其它object比，如果还是比其它object大，那么它就是最大的，否则就是返回null
 */

// 排除法，比较两个人就可以排除一个，最后还剩下一个候选人，拿这个候选人和所有人比一次。
// 和名人问题思路一样。

// similar to "The Celebrity Problem"