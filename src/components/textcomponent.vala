public class TextComponent : Engine.Component {
    public string font;
    public string text;
    public bool visible = false;
    public int timer = 0;
    public SDL.Video.Color color;

    public TextComponent(string font, string text, SDL.Video.Color color) {
        this.font = font;
        this.text = text;
        this.color = color;
    }
}
