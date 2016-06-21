/* rendersystem.c generated by valac 0.32.0, the Vala compiler
 * generated from rendersystem.vala, do not modify */

/* modules: sdl2 engine gee-0.8*/
/* vapidirs: ../../engine*/

#include <glib.h>
#include <glib-object.h>
#include <engine.h>
#include <SDL2/SDL_render.h>
#include <float.h>
#include <math.h>
#include <gee.h>
#include <SDL2/SDL_rect.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_RENDER_SYSTEM (render_system_get_type ())
#define RENDER_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_RENDER_SYSTEM, RenderSystem))
#define RENDER_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_RENDER_SYSTEM, RenderSystemClass))
#define IS_RENDER_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_RENDER_SYSTEM))
#define IS_RENDER_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_RENDER_SYSTEM))
#define RENDER_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_RENDER_SYSTEM, RenderSystemClass))

typedef struct _RenderSystem RenderSystem;
typedef struct _RenderSystemClass RenderSystemClass;
typedef struct _RenderSystemPrivate RenderSystemPrivate;

#define TYPE_TEXTURE_MANAGER (texture_manager_get_type ())
#define TEXTURE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEXTURE_MANAGER, TextureManager))
#define TEXTURE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEXTURE_MANAGER, TextureManagerClass))
#define IS_TEXTURE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEXTURE_MANAGER))
#define IS_TEXTURE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEXTURE_MANAGER))
#define TEXTURE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEXTURE_MANAGER, TextureManagerClass))

typedef struct _TextureManager TextureManager;
typedef struct _TextureManagerClass TextureManagerClass;

#define TYPE_CAMERA (camera_get_type ())
#define CAMERA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CAMERA, Camera))
#define CAMERA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CAMERA, CameraClass))
#define IS_CAMERA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CAMERA))
#define IS_CAMERA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CAMERA))
#define CAMERA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CAMERA, CameraClass))

typedef struct _Camera Camera;
typedef struct _CameraClass CameraClass;

#define TYPE_RENDER_COMPONENT (render_component_get_type ())
#define RENDER_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_RENDER_COMPONENT, RenderComponent))
#define RENDER_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_RENDER_COMPONENT, RenderComponentClass))
#define IS_RENDER_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_RENDER_COMPONENT))
#define IS_RENDER_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_RENDER_COMPONENT))
#define RENDER_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_RENDER_COMPONENT, RenderComponentClass))

typedef struct _RenderComponent RenderComponent;
typedef struct _RenderComponentClass RenderComponentClass;

#define TYPE_POSITION_COMPONENT (position_component_get_type ())
#define POSITION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_POSITION_COMPONENT, PositionComponent))
#define POSITION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_POSITION_COMPONENT, PositionComponentClass))
#define IS_POSITION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_POSITION_COMPONENT))
#define IS_POSITION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_POSITION_COMPONENT))
#define POSITION_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_POSITION_COMPONENT, PositionComponentClass))

typedef struct _PositionComponent PositionComponent;
typedef struct _PositionComponentClass PositionComponentClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_ANIMATION_COMPONENT (animation_component_get_type ())
#define ANIMATION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ANIMATION_COMPONENT, AnimationComponent))
#define ANIMATION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ANIMATION_COMPONENT, AnimationComponentClass))
#define IS_ANIMATION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ANIMATION_COMPONENT))
#define IS_ANIMATION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ANIMATION_COMPONENT))
#define ANIMATION_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ANIMATION_COMPONENT, AnimationComponentClass))

typedef struct _AnimationComponent AnimationComponent;
typedef struct _AnimationComponentClass AnimationComponentClass;

#define TYPE_COLLISION_COMPONENT (collision_component_get_type ())
#define COLLISION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COLLISION_COMPONENT, CollisionComponent))
#define COLLISION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COLLISION_COMPONENT, CollisionComponentClass))
#define IS_COLLISION_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COLLISION_COMPONENT))
#define IS_COLLISION_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COLLISION_COMPONENT))
#define COLLISION_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COLLISION_COMPONENT, CollisionComponentClass))

typedef struct _CollisionComponent CollisionComponent;
typedef struct _CollisionComponentClass CollisionComponentClass;
typedef struct _PositionComponentPrivate PositionComponentPrivate;

#define POSITION_COMPONENT_TYPE_ENTITY_STATE (position_component_entity_state_get_type ())
typedef struct _RenderComponentPrivate RenderComponentPrivate;

struct _RenderSystem {
	EngineEntitySystem parent_instance;
	RenderSystemPrivate * priv;
};

struct _RenderSystemClass {
	EngineEntitySystemClass parent_class;
};

struct _RenderSystemPrivate {
	SDL_Renderer* renderer;
	TextureManager* textureManager;
	Camera* camera;
};

typedef enum  {
	POSITION_COMPONENT_ENTITY_STATE_GROUND,
	POSITION_COMPONENT_ENTITY_STATE_AIR
} PositionComponentEntityState;

struct _PositionComponent {
	EngineComponent parent_instance;
	PositionComponentPrivate * priv;
	gint x;
	gint y;
	gint velocity_x;
	gint velocity_y;
	PositionComponentEntityState state;
	SDL_RendererFlip flip;
};

struct _PositionComponentClass {
	EngineComponentClass parent_class;
};

struct _RenderComponent {
	EngineComponent parent_instance;
	RenderComponentPrivate * priv;
	gchar* identifier;
	gchar* sprite_filename;
	guint w;
	guint h;
};

struct _RenderComponentClass {
	EngineComponentClass parent_class;
};


static gpointer render_system_parent_class = NULL;

GType render_system_get_type (void) G_GNUC_CONST;
GType texture_manager_get_type (void) G_GNUC_CONST;
gpointer camera_ref (gpointer instance);
void camera_unref (gpointer instance);
GParamSpec* param_spec_camera (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_camera (GValue* value, gpointer v_object);
void value_take_camera (GValue* value, gpointer v_object);
gpointer value_get_camera (const GValue* value);
GType camera_get_type (void) G_GNUC_CONST;
#define RENDER_SYSTEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_RENDER_SYSTEM, RenderSystemPrivate))
enum  {
	RENDER_SYSTEM_DUMMY_PROPERTY
};
RenderSystem* render_system_new (Camera* camera, SDL_Renderer* renderer, TextureManager* textureManager);
RenderSystem* render_system_construct (GType object_type, Camera* camera, SDL_Renderer* renderer, TextureManager* textureManager);
static GType* render_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1);
GType render_component_get_type (void) G_GNUC_CONST;
GType position_component_get_type (void) G_GNUC_CONST;
static void render_system_real_update (EngineSystem* base, gfloat deltaTime);
static void render_system_render (RenderSystem* self, EngineEntity* e);
GType animation_component_get_type (void) G_GNUC_CONST;
GType collision_component_get_type (void) G_GNUC_CONST;
void position_component_update_position (PositionComponent* self);
GType position_component_entity_state_get_type (void) G_GNUC_CONST;
gint camera_get_x (Camera* self);
void texture_manager_draw_frame (TextureManager* self, const gchar* identifier, SDL_Rect* dst, gint row, gint column, SDL_RendererFlip flip, SDL_Renderer* renderer);
gint animation_component_get_animation_number (AnimationComponent* self);
static void render_system_finalize (GObject* obj);


RenderSystem* render_system_construct (GType object_type, Camera* camera, SDL_Renderer* renderer, TextureManager* textureManager) {
	RenderSystem * self = NULL;
	Camera* _tmp0_ = NULL;
	SDL_Renderer* _tmp1_ = NULL;
	TextureManager* _tmp2_ = NULL;
	g_return_val_if_fail (camera != NULL, NULL);
	g_return_val_if_fail (renderer != NULL, NULL);
	g_return_val_if_fail (textureManager != NULL, NULL);
	self = (RenderSystem*) engine_entity_system_construct (object_type);
	_tmp0_ = camera;
	self->priv->camera = _tmp0_;
	_tmp1_ = renderer;
	self->priv->renderer = _tmp1_;
	_tmp2_ = textureManager;
	self->priv->textureManager = _tmp2_;
	return self;
}


RenderSystem* render_system_new (Camera* camera, SDL_Renderer* renderer, TextureManager* textureManager) {
	return render_system_construct (TYPE_RENDER_SYSTEM, camera, renderer, textureManager);
}


static GType* render_system_real_getEntityTypes (EngineEntitySystem* base, int* result_length1) {
	RenderSystem * self;
	GType* result = NULL;
	GType* _tmp0_ = NULL;
	GType* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	self = (RenderSystem*) base;
	_tmp0_ = g_new0 (GType, 2);
	_tmp0_[0] = TYPE_RENDER_COMPONENT;
	_tmp0_[1] = TYPE_POSITION_COMPONENT;
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 2;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void render_system_real_update (EngineSystem* base, gfloat deltaTime) {
	RenderSystem * self;
	self = (RenderSystem*) base;
	{
		GeeList* _e_list = NULL;
		GeeList* _tmp0_ = NULL;
		GeeList* _tmp1_ = NULL;
		gint _e_size = 0;
		GeeList* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _e_index = 0;
		_tmp0_ = ((EngineEntitySystem*) self)->entities;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_e_list = _tmp1_;
		_tmp2_ = _e_list;
		_tmp3_ = gee_collection_get_size ((GeeCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_e_size = _tmp4_;
		_e_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			EngineEntity* e = NULL;
			GeeList* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			EngineEntity* _tmp11_ = NULL;
			_tmp5_ = _e_index;
			_e_index = _tmp5_ + 1;
			_tmp6_ = _e_index;
			_tmp7_ = _e_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _e_list;
			_tmp9_ = _e_index;
			_tmp10_ = gee_list_get (_tmp8_, _tmp9_);
			e = (EngineEntity*) _tmp10_;
			_tmp11_ = e;
			render_system_render (self, _tmp11_);
			_g_object_unref0 (e);
		}
		_g_object_unref0 (_e_list);
	}
}


static void render_system_render (RenderSystem* self, EngineEntity* e) {
	RenderComponent* c = NULL;
	EngineEntity* _tmp0_ = NULL;
	gpointer _tmp1_ = NULL;
	PositionComponent* pos = NULL;
	EngineEntity* _tmp2_ = NULL;
	gpointer _tmp3_ = NULL;
	AnimationComponent* ani = NULL;
	EngineEntity* _tmp4_ = NULL;
	gpointer _tmp5_ = NULL;
	CollisionComponent* collision = NULL;
	EngineEntity* _tmp6_ = NULL;
	gpointer _tmp7_ = NULL;
	EngineEngine* _tmp8_ = NULL;
	EngineState _tmp9_ = 0;
	SDL_Rect r = {0};
	PositionComponent* _tmp11_ = NULL;
	gint _tmp12_ = 0;
	Camera* _tmp13_ = NULL;
	gint _tmp14_ = 0;
	gint _tmp15_ = 0;
	PositionComponent* _tmp16_ = NULL;
	gint _tmp17_ = 0;
	RenderComponent* _tmp18_ = NULL;
	guint _tmp19_ = 0U;
	RenderComponent* _tmp20_ = NULL;
	guint _tmp21_ = 0U;
	SDL_Rect _tmp22_ = {0};
	AnimationComponent* _tmp23_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (e != NULL);
	_tmp0_ = e;
	_tmp1_ = engine_entity_get_component (_tmp0_, TYPE_RENDER_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	c = (RenderComponent*) _tmp1_;
	_tmp2_ = e;
	_tmp3_ = engine_entity_get_component (_tmp2_, TYPE_POSITION_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	pos = (PositionComponent*) _tmp3_;
	_tmp4_ = e;
	_tmp5_ = engine_entity_get_component (_tmp4_, TYPE_ANIMATION_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	ani = (AnimationComponent*) _tmp5_;
	_tmp6_ = e;
	_tmp7_ = engine_entity_get_component (_tmp6_, TYPE_COLLISION_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	collision = (CollisionComponent*) _tmp7_;
	_tmp8_ = ((EngineSystem*) self)->engine;
	_tmp9_ = _tmp8_->state;
	if (_tmp9_ != ENGINE_STATE_PAUSED) {
		PositionComponent* _tmp10_ = NULL;
		_tmp10_ = pos;
		position_component_update_position (_tmp10_);
	}
	_tmp11_ = pos;
	_tmp12_ = _tmp11_->x;
	_tmp13_ = self->priv->camera;
	_tmp14_ = camera_get_x (_tmp13_);
	_tmp15_ = _tmp14_;
	_tmp16_ = pos;
	_tmp17_ = _tmp16_->y;
	_tmp18_ = c;
	_tmp19_ = _tmp18_->w;
	_tmp20_ = c;
	_tmp21_ = _tmp20_->h;
	memset (&_tmp22_, 0, sizeof (SDL_Rect));
	_tmp22_.x = _tmp12_ - _tmp15_;
	_tmp22_.y = _tmp17_;
	_tmp22_.w = _tmp19_;
	_tmp22_.h = _tmp21_;
	r = _tmp22_;
	_tmp23_ = ani;
	if (_tmp23_ != NULL) {
		TextureManager* _tmp24_ = NULL;
		RenderComponent* _tmp25_ = NULL;
		const gchar* _tmp26_ = NULL;
		SDL_Rect _tmp27_ = {0};
		AnimationComponent* _tmp28_ = NULL;
		gint _tmp29_ = 0;
		PositionComponent* _tmp30_ = NULL;
		SDL_RendererFlip _tmp31_ = 0;
		SDL_Renderer* _tmp32_ = NULL;
		_tmp24_ = self->priv->textureManager;
		_tmp25_ = c;
		_tmp26_ = _tmp25_->identifier;
		_tmp27_ = r;
		_tmp28_ = ani;
		_tmp29_ = animation_component_get_animation_number (_tmp28_);
		_tmp30_ = pos;
		_tmp31_ = _tmp30_->flip;
		_tmp32_ = self->priv->renderer;
		texture_manager_draw_frame (_tmp24_, _tmp26_, &_tmp27_, 0, _tmp29_, _tmp31_, _tmp32_);
	} else {
		TextureManager* _tmp33_ = NULL;
		RenderComponent* _tmp34_ = NULL;
		const gchar* _tmp35_ = NULL;
		SDL_Rect _tmp36_ = {0};
		PositionComponent* _tmp37_ = NULL;
		SDL_RendererFlip _tmp38_ = 0;
		SDL_Renderer* _tmp39_ = NULL;
		_tmp33_ = self->priv->textureManager;
		_tmp34_ = c;
		_tmp35_ = _tmp34_->identifier;
		_tmp36_ = r;
		_tmp37_ = pos;
		_tmp38_ = _tmp37_->flip;
		_tmp39_ = self->priv->renderer;
		texture_manager_draw_frame (_tmp33_, _tmp35_, &_tmp36_, 0, 0, _tmp38_, _tmp39_);
	}
	_g_object_unref0 (collision);
	_g_object_unref0 (ani);
	_g_object_unref0 (pos);
	_g_object_unref0 (c);
}


static void render_system_class_init (RenderSystemClass * klass) {
	render_system_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RenderSystemPrivate));
	((EngineEntitySystemClass *) klass)->getEntityTypes = render_system_real_getEntityTypes;
	((EngineSystemClass *) klass)->update = render_system_real_update;
	G_OBJECT_CLASS (klass)->finalize = render_system_finalize;
}


static void render_system_instance_init (RenderSystem * self) {
	self->priv = RENDER_SYSTEM_GET_PRIVATE (self);
}


static void render_system_finalize (GObject* obj) {
	RenderSystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_RENDER_SYSTEM, RenderSystem);
	G_OBJECT_CLASS (render_system_parent_class)->finalize (obj);
}


GType render_system_get_type (void) {
	static volatile gsize render_system_type_id__volatile = 0;
	if (g_once_init_enter (&render_system_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RenderSystemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) render_system_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RenderSystem), 0, (GInstanceInitFunc) render_system_instance_init, NULL };
		GType render_system_type_id;
		render_system_type_id = g_type_register_static (ENGINE_TYPE_ENTITY_SYSTEM, "RenderSystem", &g_define_type_info, 0);
		g_once_init_leave (&render_system_type_id__volatile, render_system_type_id);
	}
	return render_system_type_id__volatile;
}


