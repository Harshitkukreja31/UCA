import java.util.function.*;

class ConsumerLambda
{
	public static void main(String[] args)
	{
		Consumer<String> consumer = (p1) -> {
			System.out.println("Value used " + p1);
		};

		consumer.accept("Hi");
	}
}