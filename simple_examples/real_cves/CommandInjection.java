public class CommandInjection {
    public static void main(String[] args) {
        try {
            Runtime.getRuntime().exec(args[0]); // 사용자 입력을 직접 실행
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
