import static java.lang.Math.max;

import java.util.*;
public class pointerp2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int  n=sc.nextInt();
        int k=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        HashMap <Integer,Integer> hm=new HashMap<>();
        for(int i=0;i<k;i++){
            hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
        }
        int l=0;
        int h=k-1;
        int ans=hm.size();
        for(int i=k;i<n;i++){
            hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
            hm.put(arr[i-k],hm.getOrDefault(arr[i],0)-1);
            if (hm.get(arr[i-k])<=0) {
                hm.remove(arr[i-k]);
            }
            if (ans<hm.size()) {
                ans=hm.size();
                h=i;
                l=i-k+1;
            }
        }
        
        System.out.println(l+" "+h);
    }
}
