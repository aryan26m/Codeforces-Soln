import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class C_Number_of_Equal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int[] arr = new int[n];
        int[] arr2 = new int[s];
        
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 0; i < s; i++) {
            arr2[i] = sc.nextInt();
        }
       HashMap <Integer,Integer> hm=new HashMap<>();
       for(int i=0;i<s;i++){
        hm.put(arr2[i],hm.getOrDefault(arr2[i],0)+1);
       }
       long ans=0;
       for(int x :arr){
        if (hm.containsKey(x)) {
            ans+=hm.get(x);            
        }
       }
       System.out.println(ans);
    }
}
