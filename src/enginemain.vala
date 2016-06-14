public static void main(string [] argv) {

    var engine = new Engine();
    engine.addSystem(new RenderSystem());
    while(true) {
        engine.update();
    }
}
