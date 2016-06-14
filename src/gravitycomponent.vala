public class GravityComponent : UpdateComponent {

    public override void update() {
        var pos = this.entity.get_component<PositionComponent>();
        if(pos != null) {
            pos.next_y += 1;
        }
    }
}
