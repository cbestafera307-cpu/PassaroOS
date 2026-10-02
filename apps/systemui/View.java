public class View {

    // Posição e tamanho
    private int x;
    private int y;
    private int width;
    private int height;

    // Estado
    private boolean visible = true;
    private boolean enabled = true;
    private boolean invalidated = true;

    public View() {
        this(0, 0, 100, 100);
    }

    public View(int width, int height) {
        this(0, 0, width, height);
    }

    public View(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    // =========================
    // DESENHO
    // =========================

    /**
     * Chamado quando a View precisa ser desenhada.
     */
    protected void onDraw(Canvas canvas) {
        // Implementação padrão vazia
    }

    /**
     * Solicita que a View seja redesenhada.
     */
    public void invalidate() {
        invalidated = true;
    }

    /**
     * Renderiza a View.
     */
    public void draw(Canvas canvas) {
        if (!visible) {
            return;
        }

        if (!invalidated) {
            return;
        }

        onDraw(canvas);

        invalidated = false;
    }

    // =========================
    // TOQUE
    // =========================

    /**
     * Recebe eventos de toque.
     */
    public boolean onTouchEvent(MotionEvent event) {
        if (!enabled || !visible) {
            return false;
        }

        return false;
    }

    // =========================
    // POSIÇÃO
    // =========================

    public void setX(int x) {
        this.x = x;
        invalidate();
    }

    public void setY(int y) {
        this.y = y;
        invalidate();
    }

    public void setPosition(int x, int y) {
        this.x = x;
        this.y = y;
        invalidate();
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    // =========================
    // TAMANHO
    // =========================

    public void setWidth(int width) {
        this.width = width;
        invalidate();
    }

    public void setHeight(int height) {
        this.height = height;
        invalidate();
    }

    public void setSize(int width, int height) {
        this.width = width;
        this.height = height;
        invalidate();
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    // =========================
    // VISIBILIDADE
    // =========================

    public void setVisible(boolean visible) {
        this.visible = visible;
        invalidate();
    }

    public boolean isVisible() {
        return visible;
    }

    // =========================
    // ENABLED
    // =========================

    public void setEnabled(boolean enabled) {
        this.enabled = enabled;
        invalidate();
    }

    public boolean isEnabled() {
        return enabled;
    }

    // =========================
    // HIT TEST
    // =========================

    /**
     * Verifica se um ponto está dentro da View.
     */
    public boolean contains(int px, int py) {
        return px >= x &&
               px < x + width &&
               py >= y &&
               py < y + height;
    }
}



class Canvas {

    public void drawRect(
            int x,
            int y,
            int width,
            int height) {

        System.out.println(
            "drawRect(" +
            x + ", " +
            y + ", " +
            width + ", " +
            height + ")"
        );
    }
}

class MotionEvent {

    public static final int ACTION_DOWN = 0;
    public static final int ACTION_UP = 1;
    public static final int ACTION_MOVE = 2;

    private int action;
    private int x;
    private int y;

    public MotionEvent(int action, int x, int y) {
        this.action = action;
        this.x = x;
        this.y = y;
    }

    public int getAction() {
        return action;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}



class MyView extends View {

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawRect(
            getX(),
            getY(),
            getWidth(),
            getHeight()
        );
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            System.out.println("TOCOU NA VIEW!");
            return true;
        }

        return false;
    }
}

public class Main {

    public static void main(String[] args) {

        Canvas canvas = new Canvas();

        MyView view = new MyView(10, 20, 200, 100);

        view.draw(canvas);

        MotionEvent event =
            new MotionEvent(
                MotionEvent.ACTION_DOWN,
                50,
                40
            );

        if (view.contains(event.getX(), event.getY())) {
            view.onTouchEvent(event);
        }
    }
}

