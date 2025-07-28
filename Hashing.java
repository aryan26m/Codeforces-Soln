import java.util.*;

public class Hashing {
    String s;
    int n;
    int primes;
    long[] hashPrimes = {1000000009L, 100000007L};
    final long base = 31L;
    List<List<Long>> hashValues = new ArrayList<>();
    List<List<Long>> powersOfBase = new ArrayList<>();
    List<List<Long>> inversePowersOfBase = new ArrayList<>();

    public Hashing(String a) {
        s = a;
        n = s.length();
        primes = hashPrimes.length;

        for (int i = 0; i < primes; i++) {
            powersOfBase.add(new ArrayList<>(Collections.nCopies(n + 1, 0L)));
            inversePowersOfBase.add(new ArrayList<>(Collections.nCopies(n + 1, 0L)));
            powersOfBase.get(i).set(0, 1L);

            for (int j = 1; j <= n; j++) {
                powersOfBase.get(i).set(j, (base * powersOfBase.get(i).get(j - 1)) % hashPrimes[i]);
            }

            inversePowersOfBase.get(i).set(n, mminvprime(powersOfBase.get(i).get(n), hashPrimes[i]));
            for (int j = n - 1; j >= 0; j--) {
                inversePowersOfBase.get(i).set(j, modMul(inversePowersOfBase.get(i).get(j + 1), base, hashPrimes[i]));
            }
        }

        for (int i = 0; i < primes; i++) {
            hashValues.add(new ArrayList<>(Collections.nCopies(n, 0L)));
            for (int j = 0; j < n; j++) {
                hashValues.get(i).set(j, ((s.charAt(j) - 'a' + 1L) * powersOfBase.get(i).get(j)) % hashPrimes[i]);
                hashValues.get(i).set(j, (hashValues.get(i).get(j) + (j > 0 ? hashValues.get(i).get(j - 1) : 0L)) % hashPrimes[i]);
            }
        }
    }

    public List<Long> substringHash(int l, int r) {
        List<Long> hash = new ArrayList<>(Collections.nCopies(primes, 0L));
        for (int i = 0; i < primes; i++) {
            long val1 = hashValues.get(i).get(r);
            long val2 = l > 0 ? hashValues.get(i).get(l - 1) : 0L;
            hash.set(i, modMul(modSub(val1, val2, hashPrimes[i]), inversePowersOfBase.get(i).get(l), hashPrimes[i]));
        }
        return hash;
    }

    private long modSub(long a, long b, long mod) {
        return ((a - b) % mod + mod) % mod;
    }

    private long modMul(long a, long b, long mod) {
        return (a * b) % mod;
    }

    private long mminvprime(long a, long mod) {
        // Using modular exponentiation to find the modular multiplicative inverse
        return modExp(a, mod - 2, mod);
    }

    private long modExp(long base, long exp, long mod) {
        long res = 1L;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
String s=sc.next();
Hashing hs = new Hashing(s);
HashSet<List<Long>> hs1 = new HashSet<>();
for(int i=0;i<s.length();i++){
    for(int j=i;j<s.length();j++){
        List<Long> hash = hs.substringHash(i,j);
        hs1.add(hash);
    }
  }

System.out.println("Unique substring - - -  -"+hs1.size());
}
}
