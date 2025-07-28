import java.util.*;
import java.io.*;
import java.math.*;
public class tcs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.nextLine();
        int n=s.length();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        // int arr[]=enterarr(n);
        int answer=0;
        for(int i=0;i<n-1;i++){
            ArrayList <Integer> ar =new ArrayList<>();
            if (s.charAt(i)==s.charAt(i+1)) {
                int strt = i;
                int ed = i+1;
                ar.add(arr[strt]);
                while (ed<n && (s.charAt(strt))==((s.charAt(ed)))) {
                    ar.add(arr[ed]);
                    ed++;
                }
                if (ar.size()!=0) {
                    Collections.sort(ar);
                    for(int j=0;j<ar.size()-1;j++){
                        answer+=ar.get(j);
                    }
                }
                i=ed-1;
            }
        }
        System.out.print(answer);
    }

}

