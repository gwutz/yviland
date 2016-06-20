public class Camera {
    public int x {get; set;}
    public int y {get; set;}
    public uint w {get; set;}
    public uint h {get; set;}

    public Camera(int x, int y, uint w, uint h) {
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }
}
