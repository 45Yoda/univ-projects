import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import Login from '../views/auth/Login.vue'
import Register from '../views/auth/Register.vue'
import DashBoard from '../views/Dashboard.vue'
import Planos from '../views/Planos.vue'
import Profile from '../views/eProfile.vue'
import store from '../store/modules/token';
import userStats from '../views/userStats'

import About from '../views/About'
import Faq from '../views/Faq'
import Apoio from '../views/Apoio'


Vue.use(VueRouter)

const ifAuthenticated = (to, from, next) => {
  if (store.state.token != null) {
    next()
    return
  }
  next('/')
}


const routes = [
  {
    path: '/',
    name: 'home',
    component: Home
  },
  {
    path: '/login',
    name: 'login',
    component: Login
  },
  {
    path: '/register',
    name: 'register',
    component: Register
  },
  {
    path: '/dashboard',
    name: 'dashboard',
    component: DashBoard,
    beforeEnter: ifAuthenticated
  },
  {
    path: '/stats',
    name: 'stats',
    component: userStats,
    beforeEnter: ifAuthenticated

  },
  {
    path: '/planos',
    name: 'planos',
    component: Planos,
    beforeEnter: ifAuthenticated
  },
  {
    path: '/profile',
    name: 'editprofile',
    component: Profile,
    beforeEnter: ifAuthenticated
  },
  {
    path: '/about',
    name: 'about',
    component: About
  },
  {
    path: '/faq',
    name: 'frequentlyasked',
    component: Faq,
  },
  {
    path: '/apoio',
    name: 'apoiotécnico',
    component: Apoio,
  },


  // {
  //   path: '/about',
  //   name: 'about',
  //   // route level code-splitting
  //   // this generates a separate chunk (about.[hash].js) for this route
  //   // which is lazy-loaded when the route is visited.
  //   component: () => import(/* webpackChunkName: "about" */ '../views/About.vue')
  // }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
