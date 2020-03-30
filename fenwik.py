#Take input
print("1st line of input is a number n, denoting number of numbers, next n lines each contain a number(value of that index)")
n=int(input())
arr=[0]
for i in range(1,n+1):
    arr.append(int(input()))


#function to build fenwik tree
fenwik_tree=[None for i in range(n+1)]
def build_fenwik_tree(arr,start,end):
    if start<=end:
		if fenwik_tree[start] is None:            
		    fenwik_tree[start]=arr[start]
		    pow2=2
		    while True:
		        prev_index=start+(pow2//2)-1
		        next_index=start+pow2-1
		        if next_index<= end:
		            build_fenwik_tree(arr,prev_index+1,next_index-1)
		            fenwik_tree[next_index]=fenwik_tree[prev_index]+sum(arr[prev_index+1:next_index+1])		            
		            pow2=pow2*2
		        else:
		        	break
		    
		    build_fenwik_tree(arr,start+(pow2//2),end)
    

build_fenwik_tree(arr,1,n)    
print(fenwik_tree)        

def prefix_sum(start,end):
	prefix_sum1=0#prefix sum from 1 to start-1
	prefix_sum2=0#prefix sum from 1 to end
	start=start-1
	while start>0:
		prefix_sum1+=fenwik_tree[start]
		start-=start&(-start)
	while end>0:
		prefix_sum2+=fenwik_tree[end]
		end-=end&(-end)
	print(prefix_sum2-prefix_sum1)
	
def add(index,val):
	while index<=n:
		fenwik_tree[index]+=val
		index += index & (-index)
		
while True:
	print("........MENU.........")	
	print("1. sum values from start index to end index[1-based index]")
	print("2. add value to a particular index[1-based index]")
	print("3. exit")
	choice=int(input("enter ur choice:"))
	if choice == 1:
		start=int(input("enter start index"))
		end=int(input("enter end index"))
		prefix_sum(start,end)
	if choice == 2:
		index=int(input("enter index"))
		val=int(input("enter value"))
		add(index,val)
	if choice == 3:
		break
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
