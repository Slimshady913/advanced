import java.util.HashMap;

public class Dictionary {
    public static void main(String[] args) {
        // Create a HashMap to store words and their meanings
        HashMap<String, String> dictionary = new HashMap<>();

        // Add key-value pairs to the HashMap
        dictionary.put("Java", "A high-level programming language.");
        dictionary.put("HashMap", "A data structure that stores key-value pairs.");
        dictionary.put("Algorithm", "A step-by-step procedure for solving a problem.");
        dictionary.put("Data", "Information processed or stored by a computer.");

        // Retrieve and print a value using a key
        String meaning = dictionary.get("Java");
        System.out.println("Meaning of 'Java': " + meaning);

        // Check if a key exists in the HashMap
        if (dictionary.containsKey("Algorithm")) {
            System.out.println("The dictionary contains the word 'Algorithm'.");
        }

        // Check if a value exists in the HashMap
        if (dictionary.containsValue("A data structure that stores key-value pairs.")) {
            System.out.println("The dictionary contains the definition for 'HashMap'.");
        }

        // Iterate over the HashMap and print all key-value pairs
        System.out.println("\nAll entries in the dictionary:");
        for (String key : dictionary.keySet()) {
            System.out.println(key + ": " + dictionary.get(key));
        }

        // Remove an entry from the HashMap
        dictionary.remove("Data");
        System.out.println("\nAfter removing 'Data':");
        for (String key : dictionary.keySet()) {
            System.out.println(key + ": " + dictionary.get(key));
        }

        // Clear all entries in the HashMap
        dictionary.clear();
        System.out.println("\nDictionary cleared. Size: " + dictionary.size());
    }
}