package test;
/*
Java String, StringBuffer, StringBuilder performance comparison
String:21 ms
StringBuffer:4 ms
StringBuilder:2 ms
*/

public class TestString {
	private static final String TEST = "";

	public static void main(String[] args) {
		int N = (int) 1E5;

		// String: stored in constant string pool, immutable, slow
		String str = null;
		long t = System.currentTimeMillis();
		for (int i = N; i > 0; i--) {
			str += TEST;
		}
		System.out.println("String:" + (System.currentTimeMillis() - t) + " ms");

		// StringBuffer: in heap, mutable, slow
		StringBuffer sb = new StringBuffer(); // slow
		t = System.currentTimeMillis();
		for (int i = N; i > 0; i--) {
			sb.append(TEST);
		}
		System.out.println("StringBuffer:" + (System.currentTimeMillis() - t) + " ms");

		// StringBuilder: in heap, mutable, fast
		// recommended, despite not thread safe
		StringBuilder s = new StringBuilder();
		t = System.currentTimeMillis();
		for (int i = N; i > 0; i--) {
			s.append(TEST);
		}
		str = s.toString();
		System.out.println("StringBuilder:" + (System.currentTimeMillis() - t) + " ms");
	}
}
