import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'
import Event from './views/Event.vue'
import Single from './views/Single.vue'
import Team from './views/Team.vue'
import Player from './views/Player.vue'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/events',
      name: 'events',
      component: Event
    },
    {
      path: '/about',
      name: 'about',
      // route level code-splitting
      // this generates a separate chunk (about.[hash].js) for this route
      // which is lazy-loaded when the route is visited.
      component: () => import(/* webpackChunkName: "about" */ './views/About.vue')
    },
    {
      path: '/events/:id',
      component: Single,
      children: [
        {
          path: ':id/team/:team',
          name: 'team',
          component: Team,
        },
        {
          path: ':id/player/:team/:n',
          name: 'player',
          component: Player
        }
      ]
    }
    
  
  ]
})
