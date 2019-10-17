import java.util.Scanner;

class permutationOfString
{
	public static String swap(int low,int high,String text)
	{
		char temp;
		char temparr[] = text.toCharArray();
		temp = temparr[low];
		temparr[low] = temparr[high];
		temparr[high] = temp;
		return String.valueOf(temparr);
	}

	public static void permutationString(int low,int high,String text)
	{
		if(low == high)
		{
			System.out.println(text);
		}
		else
		{
			for(int i=low;i<=high;i++)
			{
				text = swap(low,i,text);
				permutationString(low+1,high,text);
				text = swap(low,i,text);
			}
		}
	}

	public static void main(String[] args) 
	{
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter No till u want Binary String : ");	
		String text = obj.nextLine();
		int len = text.length();
		permutationString(0,len-1,text);
	}
}