/* this is a greedy type algo to find maximize profit it takes weight and value and find maximum profit */ 

import java.util.Scanner;

class knapsack
{
	public static double calRatio(int a,int b)
	{
		double res;
		res = (double)(b/a);
		return res;
	}

	public static double knapalgo(int wt[],int val[],int cap)
	{
		double valwt[] = new double[wt.length];
		double totalVal = 0;
		
		for(int i=0;i<wt.length;i++)
		{
			valwt[i] = calRatio(wt[i],val[i]);
		}
		// for(int i=0;i<wt.length;i++)
		// {
		// 	System.out.println(valwt[i]);
		// }
		while(cap>0)
		{
			double max = valwt[0];
			int index = 0;
			for(int i=1;i<valwt.length;i++)
			{
				if(max<valwt[i])
				{
					max = valwt[i];
					index = i;
				}
			}
			valwt[index] = -1;
			if(cap-wt[index] >= 0 )
			{
				cap = cap-wt[index];
				totalVal = totalVal+val[index];
			}
			else
			{
				double fraction = ((double)cap/(double)wt[index]);
				totalVal += (val[index]*fraction);
				cap = (int)(cap - (wt[index]*fraction));
				break;
			}
		}

		
		return totalVal;
	}

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Size : ");
		int n = sc.nextInt();

		int wt[] = new int[n];
		int val[] = new int[n];

		System.out.println("Enter Weight Elements : ");
		for(int i=0;i<n;i++)
		{
			wt[i] = sc.nextInt();
		}

		System.out.println("Enter Value Elements : ");
		for(int i=0;i<n;i++)
		{
			val[i] = sc.nextInt();
		}

		System.out.println("Enter Capacity : ");
		int cap = sc.nextInt();

		double res = knapalgo(wt,val,cap);
		System.out.println(res);
		
	}
}