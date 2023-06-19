# Merits and De-merits of these different styles #

## bubble sort ##

___Complexity:- O(n^2), Space(1)___   
where n : input size <br />

> merits: 
* It's a good one to begin learning and sorts in place.
* It can be effective if the input is short length & if it is partially sorted too.
* Easy to understand and short to write.

> De-merits: 
* Increasing size of input burns the merits to the ground.


## Selection sort ##

___Complexity:- O(n^2), Space(1)___

> merits: 
* Similar to bubble sort in terms of input and sorts in place.
* Easy to understand and short to write.

> De-merits: 
* Similar to bubble, doesn't perform good on increasing input size.


## Insertion sort ##

___Complexity:- O(n^2), Space(1)___

> merits: 
* It also sorts in place.
* Easy to understand and short to write.

> De-merits: 
* Doesn't perform good on increasing input size.

## Heap sort ##

___Complexity:- O(n*log(n)), Space(1)___

> merits: 
* Efficient for all input sizes.
* It also sorts in place.
* Can be tuned for priority queue also, by reversing MAX HEAP to MIX HEAP.
* Provides a good balance of time and space complexity.

> De-merits: 
* Grasping it may take some time, as it visualizes the sequences as a tree, other than regular array, performing the sort in a very logical and lesser visible manner.


## Merge sort ##

___Complexity:- O(n*log(n)), Space(n)___

> merits: 
* Efficient for all input sizes.

> De-merits: 
* Partitions the input into n pieces, before joining them again in sorted manner, takes space equal to the input size.


## Quick sort ##

___Complexity:- O(n*log(n)), Space(1)___

> merits: 
* Can be tuned as stable, however this one is not.
* Efficient for all input sizes.
* Like Heap sort, it also provides a good balance of time and space complexity.

> De-merits: 
* It doesn't do anything different for an input that is already sorted, performing worse than other sorts in this case.


## Counting sort ##

___Complexity:- O(n+k), Space(n)___   
where k : range of the input, for ex 1..99 <br />

> merits: 
* Efficient for numbers within a decent range, because it uses them as an index of array.
* Stands apart from other styles as it doesn't compare any two elements.

> De-merits: 
* Prepares a frequency counter using some space(k), if the input range is narrow, then the extra space may not be an issue.
* Not very good for a very large input.


## Shell sort ##

___Complexity:- O(n^2), Space(1)___   
<br />

> merits: 
* sorts in place.
* Improvement over Insertion sort, sorts elements on a gap first, reducing those many move operations done to shift element from right to left.

> De-merits: 
* Doesn't perform good for large inputs.