using SDL.Video;
using Tiled;

public class TilemapRenderSystem : Engine.EntitySystem {

    private weak Renderer renderer;
    private weak TextureManager textureManager;
    private Gee.List<Engine.Entity> entities;
    private weak Camera camera;
    private bool loaded = false;

    public TilemapRenderSystem(Camera camera, Renderer renderer, TextureManager textureManager) {
        this.camera = camera;
        this.renderer = renderer;
        this.textureManager = textureManager;
    }

    public void loadTexture() {
        foreach (Engine.Entity e in entities) {
            var c = e.get_component<TilemapComponent2>();
            foreach( Tileset ts in c.map.tileset ){
                textureManager.load (ts.name, "data/" + ts.image.source, renderer);
            }
        }
    }

    public override void update(float deltaTime) {
        this.entities = this.engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
                    { typeof(TilemapComponent2) }
        ));
        if(!loaded) {
            loadTexture();
            loaded = true;
        }
        foreach (Engine.Entity e in entities) {
            var c = e.get_component<TilemapComponent2>();
            render_map(c);
        }
    }

    private void render_map(TilemapComponent2 c) {
        for( int i = 0;i < c.map.height;i++ ){
            for( int j = 0;j < c.map.width;j++ ){
                var tilenumber = j + i * c.map.width;
                var dst = Rect () {
                    x = j * c.map.tilewidth - camera.x, y = i * c.map.tileheight, w = c.map.tilewidth, h = c.map.tileheight
                };
                int row = c.map.layer[0].data.tiles[tilenumber].gid / c.map.tileset[0].columns;
                int column = c.map.layer[0].data.tiles[tilenumber].gid % c.map.tileset[0].columns - 1;

                textureManager.draw_frame (c.map.tileset[0].name,
                              dst,
                              row,
                              column,
                              RendererFlip.NONE,
                              renderer);
                /*if( this.map.layer[0].data.tiles[tilenumber].gid < 128 && this.map.layer[0].data.tiles[tilenumber].gid > 0 ){

                    r.set_draw_color (150, 120, 255, 100);
                    r.fill_rect (dst);
                }*/
            }
        }
    }
}
