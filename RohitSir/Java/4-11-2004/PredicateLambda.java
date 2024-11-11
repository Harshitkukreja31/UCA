import java.util.function.*;

public class PredicateLambda {
    public static void main(String[] args)
    {
        // Works as a Boolean Functions
        Predicate<Integer> predicate = (p1) -> {
            
            return (p1&1) == 0;
        };

        
        System.out.println(predicate.test(2));
        System.out.println(predicate.test(3));
        System.out.println(predicate.test(123));
    }
    
}
