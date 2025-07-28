import java.util.*;

class Customer {
    int a, b;

    Customer(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

public class E_Best_Price {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while (t-- >0) {
            
        
        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Customer> customers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            customers.add(new Customer(a, b));
        }

        // Sort customers by their willingness to leave a positive review
        customers.sort(Comparator.comparingInt(c -> c.a));

        // Binary Search to determine the maximum possible price
        int low = 0, high = 1000000;
        int bestPrice = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canSellAtPrice(mid, customers, k)) {
                bestPrice = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Calculate earnings at the best price
        long earnings = calculateEarnings(bestPrice, customers, k);
        System.out.println(earnings);
        sc.close();
    }
    }
    private static boolean canSellAtPrice(int price, List<Customer> customers, int maxNegativeReviews) {
        int negativeReviews = 0;
        for (Customer customer : customers) {
            if (customer.a < price && customer.b < price) {
                return false;
            } else if (customer.a < price) {
                negativeReviews++;
                if (negativeReviews > maxNegativeReviews) {
                    return false;
                }
            }
        }
        return true;
    }

    private static long calculateEarnings(int price, List<Customer> customers, int maxNegativeReviews) {
        long earnings = 0;
        int negativeReviews = 0;

        for (Customer customer : customers) {
            if (customer.a >= price) {
                earnings += price;
            } else if (customer.b >= price) {
                earnings += price;
                negativeReviews++;
                if (negativeReviews > maxNegativeReviews) {
                    break;
                }
            }
        }

        return earnings;
    }
}
