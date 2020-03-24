
import java.util.Scanner;

class Main 
{ 
    // Driver method 
    public static void main(String args[]) throws Exception 
    { 
        
			String given = "12:00:00AM";
        String dt[] = given.split(":");
        dt[2] = dt[2].substring(0,2);

        char time = given.charAt(8);
        int arr[] = new int[dt.length];
        int i=0;
        for(String str:dt)
        {
            arr[i++] = Integer.parseInt(str,10);
        }
        // for(int X:arr)
        //     System.out.print(X+" ");
        // System.out.print(time+" ");

        StringBuffer ans = new StringBuffer(given);
        ans.setLength(8);

        if(time == 'A')
        {
            if(arr[0] == 12)
            {    ans.setCharAt(0,'0');
                 ans.setCharAt(1,'0');
            }

        }
        else
        {
            if(arr[0] != 12)
            { 
                int hours = arr[0]+12;
                ans.setCharAt(0,(char)(hours/10 +'0'));
                ans.setCharAt(1,(char)(hours%10 +'0'));
            } 
        }
        System.out.println(ans);

    } 
} 
