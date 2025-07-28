import java.util.*;

class Person {
    int arrival;
    int departure;
    int index;
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int counter = 0;

        List<Person> arr = new ArrayList<>(n);
        List<Integer> answer = new ArrayList<>(Collections.nCopies(n, 0));
        TreeSet<Map.Entry<Integer, Integer>> rooms = new TreeSet<>(Map.Entry.comparingByKey());

        for (int i = 0; i < n; i++) {
            Person p = new Person();
            p.arrival = sc.nextInt();
            p.departure = sc.nextInt();
            p.index = i;
            arr.add(p);
        }

        arr.sort(Comparator.comparingInt(a -> a.arrival));

        for (Person person : arr) {
            int roomNumber;

            if (rooms.isEmpty() || rooms.first().getKey() > person.arrival) {
                roomNumber = ++counter;
            } else {
                roomNumber = rooms.first().getValue();
                rooms.pollFirst();
            }

            answer.set(person.index, roomNumber);
            rooms.add(new AbstractMap.SimpleEntry<>(person.departure + 1, roomNumber));
        }

        for (int i = 0; i < n; i++) {
            System.out.println("Person " + i + " assigned to room " + answer.get(i));
        }
    }
}
