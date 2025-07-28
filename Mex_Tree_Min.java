import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * template
 */
public class Mex_Tree_Min {
    static Scanner sc = new Scanner(System.in); // Declare Scanner as static
    public static int[] enterarr(int N) {
        int[] arr = new int[N];
        for(int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        return arr;
    }
class Multiset<T extends Comparable<T>> {
        private final TreeSet<T> treeSet;
        private final HashMap<T, Integer> countMap;
        private int size;

        public Multiset() {
            this.treeSet = new TreeSet<>();
            this.countMap = new HashMap<>();
            this.size = 0;
        }

        public void add(T element) {
            treeSet.add(element);
            countMap.put(element, countMap.getOrDefault(element, 0) + 1);
            size++;
        }

        public void remove(T element) {
            if (!countMap.containsKey(element)) return;
            int count = countMap.get(element);
            if (count == 1) {
                countMap.remove(element);
                treeSet.remove(element);
            } else {
                countMap.put(element, count - 1);
            }
            size--;
        }

        public T first() {
            return treeSet.first();
        }

        public T last() {
            return treeSet.last();
        }

        public T pollFirst() {
            T first = first();
            remove(first);
            return first;
        }

        public T pollLast() {
            T last = last();
            remove(last);
            return last;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public int size() {
            return size;
        }
    }
   public static void printarr(int[] arr) {
        // For debugging only
        for(int x: arr)
            System.out.print(x);
        System.out.println();
    }
    public static boolean isPrime(long n)
    {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }
    public static long gcd(long a, long b)
    {
        if(a > b)
            a = (a+b)-(b=a);
        if(a == 0L)
            return b;
        return gcd(b%a, a);
    }
    public static int[] sort(int[] arr)
    {
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
            return arr;
    }
    public static void push(TreeMap<Integer, Integer> map, int k, int v)
    {
        //map[k] += v;
        if(!map.containsKey(k))
            map.put(k, v);
        else
            map.put(k, map.get(k)+v);
    }
    public static Comparator <Integer> getComparator()
    {
        return  new Comparator <Integer> () {
        @Override
            public int compare (Integer num1 , Integer num2) {
            if(num1<num2){return 1;} 
            else if(num1>num2){return -1;} 
       return 0;
            }
            };
    }
public static boolean search(int arr[],int target){
 int n=arr.length;
int low=0;
 int high=n-1;
 while(low<=high){
    int mid = low+((high-low)/2);
    if(arr[mid
                ]==target){
        return true;
                }
    else if(arr[mid
                ]>target){
        high=mid-1;
                }
    else{
        low=mid+1;
                }
            }
return false;
        }

public static int lowerBound(int arr[],int x){
        int n=arr.length;
        int ans=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check1(arr,mid,x)==1) {
                ans=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return ans;
    }
    public static int check1(int arr[],int mid ,int x){
        if (arr[mid]>=x) {
            return 1;
        }
        else{
            return 0;
        }
    }
    public static int upperbBound(int arr[],int x){
        int n=arr.length;
        int ans=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check2(arr,mid,x)==1) {
                ans=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return ans;
    }
    public static int check2(int arr[],int mid ,int x){
        if (arr[mid]>x) {
            return 1;
        }
        else{
            return 0;
        }
    }
    static final int MAX_NODES = 2005;
static int no;
static List<Integer>[] tree = new ArrayList[MAX_NODES];
static int[] nde = new int[MAX_NODES];
static int[][] ancs = new int[12][MAX_NODES];
static int[] ndpt = new int[MAX_NODES];
static BitSet[] lbl = new BitSet[MAX_NODES];

static {
for (int i = 0; i < MAX_NODES; i++) {
   tree[i] = new ArrayList<>();
   lbl[i] = new BitSet(MAX_NODES);
}
}

    public static void main(String[] args) {
        int t=sc.nextInt();
        while(t-- >0) {

      no = sc.nextInt();

        for (int i = 1; i <= no; i++) {
            tree[i].clear();
        }

        for (int i = 0; i < no - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            tree[u].add(v);
            tree[v].add(u);
        }

        asgn();

        dfs(1, -1);

        buildas();

        int mxx = 0;

        BitSet cmbr = new BitSet(MAX_NODES);

        for (int u = 1; u <= no; u++) {
            for (int v = u; v <= no; v++) {
                int lca = glca(u, v);

                cmbr.clear();
                cmbr.or(lbl[u]);
                cmbr.or(lbl[v]);

                if (ancs[0][lca] >= 1)
                    cmbr.andNot(lbl[ancs[0][lca]]);

                int mex = 0;
                while (cmbr.get(mex)) mex++;
                mxx += mex;
            }
        }

        System.out.println(mxx);
    }  
    }
    static void asgn() {
        int[] dnt = new int[no + 1];
        boolean[] isLeaf = new boolean[no + 1];
        Arrays.fill(dnt, -1);
        Arrays.fill(isLeaf, true);

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= no; i++) {

            if (tree[i].size() > 1) isLeaf[i] = false;

            if (isLeaf[i]) {

                dnt[i] = 0;

                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int nbr : tree[current]) {

                if (dnt[nbr] == -1) {

                    dnt[nbr] = dnt[current] + 1;
                    queue.add(nbr);
                }
            }
        }

        List<int[]> vec = new ArrayList<>();
        for (int i = 1; i <= no; i++) {
            vec.add(new int[]{dnt[i], i});
        }

        vec.sort(Comparator.comparingInt(a -> a[0]));

        for (int i = 0; i < no; i++) {
            int nodeId = vec.get(i)[1];
            nde[nodeId] = i;
        }
    }

    static void dfs(int crnt, int prnt) {

        ancs[0][crnt] = prnt;

        ndpt[crnt] = (prnt == -1) ? 0 : ndpt[prnt] + 1;

        lbl[crnt] = (prnt == -1) ? new BitSet(MAX_NODES) : (BitSet) lbl[prnt].clone();
        
        lbl[crnt].set(nde[crnt]);

        for (int nbr : tree[crnt]) {

            if (nbr != prnt) {

                dfs(nbr, crnt);
            }
        }
    }

    static void buildas() {

        for (int k = 1; k < 12; k++) {


            for (int i = 1; i <= no; i++) {

                int mid = ancs[k - 1][i];

                ancs[k][i] = (mid == -1) ? -1 : ancs[k - 1][mid];
            }
        }
    }

    static int glca(int u, int v) {
        if (ndpt[u] < ndpt[v]) {

            int temp = u;
            u = v;

            v = temp;
        }

        int diff = ndpt[u] - ndpt[v];
        for (int k = 0; k < 12; k++) {

            if ((diff & (1 << k)) > 0)
             {
                u = ancs[k][u];
            }
        }

        if (u == v) return u;

        for (int k = 11; k >= 0; k--) {
            if (ancs[k][u] != ancs[k][v])
             {
                u = ancs[k][u];
                v = ancs[k][v];
            }
        }

        return ancs[0][u];
    }
}
