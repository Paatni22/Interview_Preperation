/* IMPORTANT: Multiple classes and nested static classes are supported */

//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;


// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input
        */
        //BufferedReader
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // String name = br.readLine();                // Reading input from STDIN
        // System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner s = new Scanner(System.in);
        Scanner sc = new Scanner(System.in);
       // String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        
        int t;
        t = s.nextInt();
        for(int i=0;i<t;i++)
        {
            String str;
            str = sc.next();
            Validator v = new Validator(str);
            String op = v.IsValid();
            System.out.println(op);
        }


        // Write your code here

    }
}
class Validator
{
    String str;
    Validator(String str)
    {
        this.str = str;
    }
    public String IsValid()
    {
        try
        {
            int numeric = Integer.parseInt(this.str);
            return "Valid Format";

            /*
Valid Format
Its an AlphaNumeric
Its a String*/
        }
        catch(NumberFormatException no)
        {
            try
            {
                for(int i=0;i<str.length();i++)
                {
                    char ch = str.charAt(i);
                    if(ch >='0' && ch<='9')
                        throw new AlphaNumericException();

                }
                throw new StringException();
            }
            catch(AlphaNumericException a)
            {
                return a.toString();
            }
            catch(StringException s)
            {
                return s.toString();
            }
                       
        }
    }
}
class AlphaNumericException extends Exception
{
    public String toString()
    {
        return "Its an AlphaNumeric";
    }
}
class StringException extends Exception
{
    public String toString()
    {
        return "Its a String";
    }
}
