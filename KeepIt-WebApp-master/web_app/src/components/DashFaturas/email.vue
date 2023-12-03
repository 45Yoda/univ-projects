<template>
  <v-container fluid>
    <!-- <v-combobox
      v-model="model"
      hide-selected
      label="Email para partilhar recibo"
      multiple
      small-chips
      solo
    >
      <template v-slot:selection="{ attrs, item, parent, selected }">
        <v-chip
          v-if="item === Object(item)"
          v-bind="attrs"
          :color="`${item.color} lighten-3`"
          :input-value="selected"
          label
          small
        >
          <span class="pr-2">{{ item.text }}</span>
          <v-icon small @click="remove(item)">mdi-close</v-icon>
        </v-chip>
      </template>
    </v-combobox>-->
    <v-combobox
      :rules="[v => !!v[0] || 'Campo obrigatório!']"
      multiple
      solo
      clearable
      v-model="email"
      chips
      deletable-chips
      label="Localização"
    ></v-combobox>
    <v-row>
      <v-col cols="12" lg="8">
        <v-select
          small
          flat
          prefix="Dividir recibo em partes iguais?"
          :items="['Sim', 'Não']"
          label
          v-model="escolha"
          solo
        ></v-select>
      </v-col>
      <v-col v-if="escolha=='Não'" cols="12" lg="4">
        <v-text-field
          v-for="mail in convertArray"
          v-bind:key="mail.email"
          v-bind:label="$t(mail.email)"
          v-model="mail.total"
          required
        ></v-text-field>
        <!-- <v-text-field v-if="escolha" v-bind:label="$t('My Label')" required></v-text-field> -->
      </v-col>
    </v-row>
  </v-container>
</template>

<script>
export default {
  data() {
    return {
      activator: null,
      valor: "",
      email: [],
      escolha: "",
      id: 0,
      attach: null,
      colors: ["green", "purple", "indigo", "cyan", "teal", "orange"],
      editing: null,
      index: -1,
      items: [],
      nonce: 1,
      menu: false,
      model: [],
      x: 0,
      search: null,
      y: 0
    };
  },
  computed: {
    convertArray() {

      return this.email.map(e => {
        let newUser = {
          email: e,
          total: 0
        };
        return newUser;
      });
    }
  },
  watch: {
    model(val, prev) {
      console.log(this.email);

      if (val.length === prev.length) return;

      this.model = val.map(v => {
        if (typeof v === "string") {
          v = {
            text: v,
            total: "",
            color: this.colors[this.nonce - 1]
          };

          this.items.push(v);

          this.nonce++;
        }

        return v;
      });
    }
  },

  methods: {
    async sendValues(valor) {
      console.log(valor);
      this.email.email = valor.text;
      this.email.total = valor.total;
      console.log(this.email);

      this.$emit("valorDiv", this.email);

      //   this.$emit("valorDiv",valor);
    },
    $t(value) {
      return value;
    },
    remove() {
      console.log(this.model);
      //   this.model.pop();
    },
    edit(index, item) {
      if (!this.editing) {
        this.editing = item;
        this.index = index;
      } else {
        this.editing = null;
        this.index = -1;
      }
    },
    filter(item, queryText, itemText) {
      if (item.header) return false;

      const hasValue = val => (val != null ? val : "");

      const text = hasValue(itemText);
      const query = hasValue(queryText);

      return (
        text
          .toString()
          .toLowerCase()
          .indexOf(query.toString().toLowerCase()) > -1
      );
    }
  }
};
</script>