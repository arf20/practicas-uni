# Mensajes

## Mensajes de control

 - distribution format
 - distribution frequency
 - magnitude unit
 - distribution enable

### XML

```
<?xml version="1.0"?>
<control>
  <format>xml</format>
  <frequency>10</frequency>
  <unit magnitude="temp">C</unit>
  <unit magnitude="pressure">hpa</unit>
  <enabled>true</enabled>
</control>
```

## Mensajes de datos

### XML

```
<?xml version="1.0"?>
<data>
  <server>anid</server>
  <temp unit="C">23</temp>
  <humidity>40</humidity>
  <pressure unit="mbar">1030</pressure>
</data>
```

