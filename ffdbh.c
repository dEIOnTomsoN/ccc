public class rightTrianlge {
  public static void main(String[] args) {

    // size of the triangle
    int size = 5;
    // loop to print the pattern
    for (int i = 0; i < size; i++) {
      // print spaces
      for (int j = 1; j < size - i; j++) {
        System.out.print(" ");
      }
      // print stars
      for (int k = 0; k <= i; k++) {
        System.out.print("*");
      }
      System.out.println();
    }
  }
}
