const state = {
    token: localStorage.getItem('access_token') || null , 
    name : null
}

const getters = {
    getToken: state => state.token,
    loggedIn: state => {
        return state.token != null
    },
    getName : state => state.name
}

const actions = {}

const mutations = {
    setToken: (state, token) => state.token = token,
    setName: (state,name) => state.name = name,
    removeToken: (state) => state.token = null
}

export default {
    state,
    getters,
    actions,
    mutations
}