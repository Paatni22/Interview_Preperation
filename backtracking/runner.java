//Runner class
import java.util.List;
class Run
{
	public static void main(String args[])
	{
		Solution ob = new Solution();
		int a[] = {1,2,3};
		List<List<Integer>> ans = ob.permute(a);

		for(List<Integer> row : ans)
		{
			for(Integer val:row)
				System.out.print(val+",");
			System.out.println();
		}

	}
}