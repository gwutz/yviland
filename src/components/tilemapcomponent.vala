using Tiled;
using SDL.Video;

public class TilemapComponent : Engine.Component {
    public Tiled.Map map;
    private weak TextureManager t;
    private weak Renderer r;

    public TilemapComponent (Tiled.Map map, TextureManager t, Renderer r) {
        this.map = map;
        foreach( Tileset ts in this.map.tileset ){
            t.load (ts.name, "data/" + ts.image.source, r);
        }
        this.t = t;
        this.r = r;
    }

    public void render(Engine.Entity camera) {
        var camerapos = camera.get_component<PositionComponent>();
        for( int i = 0;i < this.map.height;i++ ){
            for( int j = 0;j < this.map.width;j++ ){
                var tilenumber = j + i * this.map.width;
                var dst = Rect () {
                    x = j * this.map.tilewidth - camerapos.x, y = i * this.map.tileheight, w = this.map.tilewidth, h = this.map.tileheight
                };
                int row = this.map.layer[0].data.tiles[tilenumber].gid / this.map.tileset[0].columns;
                int column = this.map.layer[0].data.tiles[tilenumber].gid % this.map.tileset[0].columns - 1;
                // stdout.printf (@"$row $column %d\n", this.map.layer[0].data.tiles[tilenumber].gid);
                t.draw_frame (this.map.tileset[0].name,
                              dst,
                              row,
                              column,
                              RendererFlip.NONE,
                              r);
                /*if( this.map.layer[0].data.tiles[tilenumber].gid < 128 && this.map.layer[0].data.tiles[tilenumber].gid > 0 ){

                    r.set_draw_color (150, 120, 255, 100);
                    r.fill_rect (dst);
                }*/
            }
        }
    }

}
