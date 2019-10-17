import java.util.Scanner;

class MergeSort
{
	public static void merge(int arr[],int l,int m,int h)
	{
		int n1 = m - l + 1;
		int n2 = h-m;
		int p=0;
		int L[] = new int[n1];
		int R[] = new int[n2];

		for(int i=0;i<n1;i++)
		{
			L[i] = arr[l+i];
		}
		for(int j=0;j<n2;j++)
		{
			R[j] = arr[m+1+j];
		}

		int i=0,j=0,k=l;
		while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		} 
		while(i<n1)
		{
			arr[k] = L[i];
			k++;
			i++;
		}
		while(j<n2)
		{
			arr[k] = R[j];
			k++;
			j++;
		}
	}

	public static void sort(int arr[],int l,int h)
	{
		if(l<h)
		{
			int m = (l+h)/2;
			sort(arr,l,m);
			sort(arr,m+1,h);
			merge(arr,l,m,h);
		}
	}

	public static void printArray(int arr[])
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i] + " ");
			//System.out.println("");                                   
		}
	}

	public static void main(String[] args) 
	{
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter Array Size : ");
		int n = obj.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter Element : ");
			 arr[i] = obj.nextInt();
		}
		sort(arr,0,n-1);
		printArray(arr);
	}
}